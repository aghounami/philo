/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/20 20:40:04 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
	t_philo *table;

	if (ac < 5 || ac > 6 || parse_args(av))
		return (ft_error("Error: wrong argument s\n"));
	table = malloc(sizeof(t_philo));
	table->id = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	sem_unlink("/forks");
	sem_unlink("/print_mutex");
	table->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->forks);
	table->print_mutex = sem_open("/print_mutex", O_CREAT | O_EXCL, 0644, 0644, 1);
	if (table->print_mutex <= 0 || table->forks <= 0)
		ft_error("Error: semaphore open error");
	// table->forks = malloc(sizeof(sem_t) * ft_atoi(av[1]));
	if (table == NULL || table->id == NULL)
		return (ft_error("Error: malloc failed for philosophers\n"));
	if (ft_init_table(table, ac, av))
		return (1);
	if (ft_init_process(table))
		return (1);
	return (0);
}
