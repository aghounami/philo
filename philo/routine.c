/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:00:13 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/29 02:10:10 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	init_time(philo);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_fork);
		ft_print(philo, "has taken a fork\n");
		ft_print(philo, "is eating\n");
		ft_usleep(philo->table->time_to_eat);
		init_time(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(&philo->table->counter_mutex);
		philo->meals_counter += 1;
		pthread_mutex_unlock(&philo->table->counter_mutex);
		ft_print(philo, "is sleeping\n");
		ft_usleep(philo->table->time_to_sleep);
		ft_print(philo, "is thinking\n");
	}
	return (NULL);
}
