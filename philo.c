/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/18 22:55:05 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6 || parse_args(av))
		return (ft_error("Error: wrong argument s\n"));
	table = malloc(sizeof(t_table));
	table->philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	table->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	if (table == NULL || table->philo == NULL || table->forks == NULL)
	{
		ft_free(table);
		return (ft_error("Error: malloc failed for philosophers\n"));
	}
	if (ft_init_table(table, ac, av))
	{
		destroy_mutex(table, 0);
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
