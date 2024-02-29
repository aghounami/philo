/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/29 02:10:35 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meals_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->table->meals_mutex);
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
	table = malloc(sizeof(t_table));
	table->philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	table->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (table == NULL || table->philo == NULL || table->forks == NULL)
		return (ft_error("Error: malloc failed for philosophers\n"));
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
