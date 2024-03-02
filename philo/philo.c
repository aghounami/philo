/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/03/02 12:16:29 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_malloc(t_table **table, char **av)
{
	*table = (t_table *)malloc(sizeof(t_table));
	if (!*table)
		return (ft_error("Error: malloc failed\n"));
	(*table)->philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!(*table)->philo)
	{
		free(*table);
		return (ft_error("Error: malloc failed\n"));
	}
	(*table)->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* ft_atoi(av[1]));
	if (!(*table)->forks)
	{
		free((*table)->philo);
		free(*table);
		return (ft_error("Error: malloc failed\n"));
	}
	return (0);
}

int	ft_init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (ft_error("Error: pthread_mutex_init failed\n"));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6 || parse_args(av))
		return (ft_error("Error: wrong argument s\n"));
	if (init_malloc(&table, av))
		return (1);
	if (ft_init_table(table, ac, av))
	{
		ft_free(table);
		return (1);
	}
	if (ft_init_philo(table))
	{
		destroy_mutex(table, 1);
		return (1);
	}
	destroy_mutex(table, 1);
	return (0);
}
