/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/22 04:37:30 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_philo(t_philo *philo)
{
	int		i;
	int		status;

	i = 0;
	while (i < philo->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < philo->nb_philo)
				kill(philo->id[i], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(philo->print_semaphore);
	sem_close(philo->forks);
	sem_unlink("/print_mutex");
	sem_unlink("/forks");
	free(philo->id);
	free(philo);
}

int	ft_init_table(t_philo *table, int ac, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->nb_forks = table->nb_philo;
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	else
		table->nb_must_eat = -1;
	table->counter = 0;
	table->last_eat = 0;
	table->start = get_time();
	table->died_flag = 0;
	if (table->nb_philo == 0 || table->time_to_eat == 0
		|| table->time_to_sleep == 0)
	{
		ft_error("Error: wrong argument\n");
		return (1);
	}
	return (0);
}

int	ft_init_process(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		philo->id[i] = fork();
		if (philo->id[i] == -1)
			return (ft_error("Error: fork failed\n"));
		if (philo->id[i] == 0)
		{
			philo->philo_id = i + 1;
			philo->last_eat = get_time();
			ft_philo(philo);
		}
		i++;
	}
	exit_philo(philo);
	return (0);
}
