/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/22 21:57:42 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ini_semaphores(t_philo *table, char **av)
{
	sem_unlink("/forks");
	sem_unlink("/print_semaphore");
	sem_unlink("/died_flag_semaphor");
	sem_unlink("/meals_semaphore");
	sem_unlink("/counter_semaphore");
	table->meals_semaphore = sem_open("/meals_semaphore", \
		O_CREAT | O_EXCL, 0644, 1);
	table->counter_semaphore = sem_open("/counter_semaphore", \
		O_CREAT | O_EXCL, 0644, 1);
	table->died_flag_semaphor = sem_open("/died_flag_semaphor", \
		O_CREAT | O_EXCL, 0644, 1);
	table->forks = sem_open("/forks", \
		O_CREAT | O_EXCL, 0644, ft_atoi(av[1]));
	table->print_semaphore = sem_open("/print_semaphore", \
		O_CREAT | O_EXCL, 0644, 0644, 1);
	if (table->print_semaphore <= 0 || table->forks <= 0)
	{
		ft_error("Error: semaphore open error");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*table;

	if (ac < 5 || ac > 6 || parse_args(av))
		return (ft_error("Error: wrong argument s\n"));
	table = malloc(sizeof(t_philo));
	table->id = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (ini_semaphores(table, av) == 1)
		return (1);
	if (table == NULL || table->id == NULL)
		return (ft_error("Error: malloc failed for philosophers\n"));
	if (ft_init_table(table, ac, av))
		return (1);
	if (ft_init_process(table))
		return (1);
	return (0);
}
