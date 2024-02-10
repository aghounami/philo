/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/10 21:25:44 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_all *table;

	table = malloc(sizeof(t_all));
    if (table == NULL)
        return ft_error("Error: malloc failed\n");
	if (ac < 5 || ac > 6 || parse_args(av))
		return (ft_error("Error: wrong in arguments\n"));
	if(ft_init_table(table, ac, av))
		return (1);
	if (ft_init_forks(table))
		return (1);
	if (ft_init_philo(table))
		return (1);
	if (ft_create_threads(table))
		return (1);
	if (ft_join_threads(table))
		return (1);
	// if (ft_destroy_mutex(table))
		return (1);
	free(table->philo);
	free(table->fork);
	free(table);
	return (0);
}