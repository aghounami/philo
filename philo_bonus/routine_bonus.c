/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:00:13 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/25 23:41:24 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, \
			NULL, &check_death, philo))
		ft_error("Error: Failed to create the thread");
	while (1)
	{
		ft_print(philo, "is thinking");
		sem_wait(philo->forks);
		ft_print(philo, "has taken a fork");
		sem_wait(philo->forks);
		ft_print(philo, "has taken a fork");
		ft_print(philo, "is eating");
		ft_usleep(philo->time_to_eat);
		philo->last_eat = get_time();
		sem_post(philo->forks);
		sem_post(philo->forks);
		philo->counter += 1;
		ft_print(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep);
	}
	if (pthread_join(philo->check_monitor, NULL))
		ft_error("Error: Failed to join the thread");
}

int	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->forks);
	ft_print(philo, "has taken a fork\n");
	sem_wait(philo->forks);
	ft_print(philo, "has taken a fork\n");
	return (0);
}

int	ft_eat(t_philo *philo)
{
	ft_print(philo, "is eating\n");
	philo->last_eat = get_time();
	ft_usleep(philo->time_to_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (philo->nb_must_eat != -1)
		philo->counter++;
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping\n");
	ft_usleep(philo->time_to_sleep);
	return (0);
}

int	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking\n");
	return (0);
}
