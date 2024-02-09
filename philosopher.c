/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/09 17:47:55 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_table(t_table *table, int ac, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	else
		table->nb_must_eat = -1;
	// if (table->nb_philo < 2 || table->time_to_die < 60 || table->time_to_eat < 60
	// 	|| table->time_to_sleep < 60 || (ac == 6 && table->nb_must_eat < 1))
	// 	return (ft_error("Error: wrong in arguments\n"));
	table->end_time = false;
	table->philo = malloc(sizeof(t_philo) * table->nb_philo);
	return (0);
}
