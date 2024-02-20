/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/20 20:36:31 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_philo(t_philo **philo)
{
	t_philo	*tmp;
	int		i;
	// int		status;

	tmp = *philo;
	i = 0;
	// while (i < tmp->nb_philo)
	// {
	// 	waitpid(-1, &status, 0);
	// 	if (status != 0)
	// 	{
	// 		i = -1;
	// 		while (++i < tmp->nb_philo)
	// 			kill(tmp->id[i], SIGKILL);
	// 		break ;
	// 	}
	// 	i++;
	// }
	sem_close(tmp->print_mutex);
	sem_close(tmp->forks);
	sem_unlink("/print_mutex");
	sem_unlink("/forks");
	free(tmp->id);
	free(tmp);
}

int	ft_init_table(t_philo *table, int ac, char **av)
{
	// sem_unlink("died_flag");
	// sem_unlink("counter_mutex");
	// sem_unlink("meals_mutex");
	// table->died_flag_mutex = sem_open("died_flag", O_CREAT, 0644, 1);
	// table->counter_mutex = sem_open("counter_mutex", O_CREAT, 0644, 1);
	// table->meals_mutex = sem_open("meals_mutex", O_CREAT, 0644, 1);
	// if(table->died_flag_mutex == SEM_FAILED || table->counter_mutex == SEM_FAILED
	// 	|| table->print_mutex == SEM_FAILED || table->meals_mutex == SEM_FAILED)
	// 	return (ft_error("Error: sem_open failed\n"));
	table->nb_philo = ft_atoi(av[1]);
	table->nb_forks = table->nb_philo;
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	else
		table->nb_must_eat = -1;
	table->meals_counter = 0;
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


// int init_fork_sem(t_table *table) {
//     int i;

//     i = 0;
//     while (i < table->nb_philo)
// 	{
//         sem_unlink("forks"); // Unlink the semaphore to remove any existing one
//         table->fork[i] = sem_open("/forks", O_CREAT, 0644, table->nb_philo); // Create/open the semaphore
//         // if (table->fork[i] == SEM_FAILED) {
//         //     return ft_error("Error: sem_open failed\n");
//         // }
//         i++;
//     }
//     return 0;
// }

int ft_init_process(t_philo *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->id[i] = fork();
		if (table->id[i] == -1)
			return (ft_error("Error: fork failed\n"));
		if (table->id[i] == 0)
		{
			table->philo_id = i + 1;
			table->last_eat = get_time();
			ft_philo(table);
			// printf("%d\n", table->nb_philo);
			// exit(0);
		}
		i++;
	}
	exit_philo(&table);
	return (0);
}
