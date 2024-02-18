/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:00:13 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/18 22:56:26 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->nb_philo == 1)
	{
		ft_print(philo, "take a fork\n");
		usleep(philo->table->time_to_die * 1000);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		usleep(philo->table->time_to_eat * 1000);
	while (philo->meals_counter != philo->table->nb_must_eat)
	{
		if (ft_take_forks(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (chek_before_lock(philo, 1) == 1)
		return (1);
	ft_print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->right_fork);
	if (chek_before_lock(philo, 2) == 1)
		return (1);
	ft_print(philo, "has taken a fork\n");
	if (ft_eat(philo) == 1)
		return (1);
	if (ft_sleep(philo) == 1)
		return (1);
	if (ft_think(philo) == 1)
		return (1);
	pthread_mutex_lock(philo->table->counter_mutex);
	if (philo->table->nb_must_eat != -1)
		philo->meals_counter++;
	pthread_mutex_unlock(philo->table->counter_mutex);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->table->died_flag_mutex);
	if (philo->table->died_flag == 1)
	{
		pthread_mutex_unlock(philo->table->died_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->died_flag_mutex);
	ft_print(philo, "is eating\n");
	pthread_mutex_lock(philo->table->meals_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(philo->table->meals_mutex);
	usleep((philo->table->time_to_eat) * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->table->died_flag_mutex);
	if (philo->table->died_flag == 1)
	{
		pthread_mutex_unlock(philo->table->died_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->died_flag_mutex);
	ft_print(philo, "is sleeping\n");
	usleep((philo->table->time_to_sleep) * 1000);
	return (0);
}

int	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->table->died_flag_mutex);
	if (philo->table->died_flag == 1)
	{
		pthread_mutex_unlock(philo->table->died_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->died_flag_mutex);
	ft_print(philo, "is thinking\n");
	return (0);
}
