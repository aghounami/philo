/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:00:13 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/23 02:14:10 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		ft_usleep(100);
	pthread_create(&philo->check_monitor, NULL, check_death, philo);
	while (1)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	pthread_join(philo->check_monitor, NULL);
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
