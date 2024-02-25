/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/25 23:40:56 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_philo *table)
{
	sem_unlink("print");
	sem_unlink("forks");
	table->print = sem_open("print", O_CREAT, 0644, 1);
	table->forks = sem_open("forks", O_CREAT, \
								0644, table->nb_forks);
	if (table->print <= 0 || table->forks <= 0)
	{
		ft_error("Error: semaphore open error");
		return (1);
	}
	return (0);
}

void	exit_philo(t_philo *tmp)
{
	int		i;
	int		status;

	i = 0;
	while (i < tmp->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < tmp->nb_philo)
				kill(tmp->id[i], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(tmp->print);
	sem_close(tmp->forks);
	sem_unlink("/block_print");
	sem_unlink("/block_forks");
	free(tmp->id);
	free(tmp);
}

t_philo	*ft_init_table(int ac, char **av)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->id = malloc(sizeof(int) * ft_atoi(av[1]));
	if (!philo || !philo->id)
		return (NULL);
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_must_eat = ft_atoi(av[5]);
	else
		philo->nb_must_eat = -1;
	philo->counter = 0;
	philo->stop = 0;
	philo->died = 0;
	philo->nb_forks = philo->nb_philo;
	if (init_semaphores(philo))
		return (NULL);
	return (philo);
}

int	ft_init_process(t_philo *philo)
{
	int	i;

	i = -1;
	philo->start = get_time();
	while (++i < philo->nb_philo)
	{
		philo->id[i] = fork();
		if (philo->id[i] == -1)
			ft_error("Error: fork mistake");
		if (philo->id[i] == 0)
		{
			philo->philo_id = i + 1;
			philo->last_eat = get_time();
			ft_philo(philo);
		}
	}
	exit_philo(philo);
	return (0);
}
