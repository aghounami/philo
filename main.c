/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/18 01:02:38 by aghounam         ###   ########.fr       */
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
	if (table == NULL || table->philo == NULL)
		return (ft_error("Error: malloc failed for philosophers\n"));
	if (ft_init_table(table, ac, av))
		return (1);
	if (ft_init_philo(table))
		return (1);
	return (0);
}
