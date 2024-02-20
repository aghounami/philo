/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:00:13 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/20 20:47:23 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_philo(t_philo *philo)
{
	int		i;

	printf("philo->time_to_eat = %ld\n", philo->time_to_eat);
	printf("philo->time_to_sleep = %ld\n", philo->time_to_sleep);
	printf("philo->time_to_die = %ld\n", philo->time_to_die);
	printf("philo->nb_must_eat = %ld\n", philo->nb_must_eat);
	printf("philo->philo_id = %ld\n", philo->philo_id);
	printf("philo->nb_philo = %d\n", philo->nb_philo);
	i = (philo->time_to_eat + philo->time_to_sleep);
	if (philo->philo_id % 2 == 0)
		ft_usleep(i / 2);
	while (1)
	{
		if (ft_take_forks(philo) == 1)
			return (NULL);
		if (ft_eat(philo) == 1)
			return (NULL);
		if (ft_sleep(philo) == 1)
			return (NULL);
		if (ft_think(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	ft_take_forks(t_philo *philo)
{
	// printf("hfhfhfhfhhf\n");
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	ft_print(philo, "has taken a fork\n");
	// sem_wait(philo->forks);
	// if (chek_before_lock(philo, 2) == 1)
	// 	return (1);
	ft_print(philo, "has taken a fork\n");
	// sem_wait(philo->counter_mutex);
	// if (philo->table->nb_must_eat != -1)
	// 	philo->meals_counter++;
	// sem_post(philo->table->counter_mutex);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	// sem_wait(philo->died_flag_mutex);
	// if (philo->died_flag == 1)
	// {
	// 	sem_post(philo->table->died_flag_mutex);
	// 	return (1);
	// }
	// sem_post(philo->table->died_flag_mutex);
	ft_print(philo, "is eating\n");
	// sem_wait(philo->table->meals_mutex);
	ft_usleep(philo->time_to_eat);
	philo->last_eat = get_time();
	sem_post(philo->forks);
	sem_post(philo->forks);
	// sem_post(philo->table->meals_mutex);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	// sem_wait(philo->died_flag_mutex);
	// if (philo->died_flag == 1)
	// {
	// 	sem_post(philo->died_flag_mutex);
	// 	return (1);
	// }
	// sem_post(philo->died_flag_mutex);
	ft_print(philo, "is sleeping\n");
	ft_usleep(philo->time_to_sleep);
	return (0);
}

int	ft_think(t_philo *philo)
{
	// sem_wait(philo->table->died_flag_mutex);
	// if (philo->table->died_flag == 1)
	// {
	// 	sem_post(philo->table->died_flag_mutex);
	// 	return (1);
	// }
	// sem_post(philo->table->died_flag_mutex);
	ft_print(philo, "is thinking\n");
	return (0);
}
