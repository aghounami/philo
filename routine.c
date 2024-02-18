/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:00:13 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/18 00:54:55 by aghounam         ###   ########.fr       */
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

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->table->print_mutex);
	printf("%ld %d %s", get_time() - philo->start, philo->id, str);
	pthread_mutex_unlock(philo->table->print_mutex);
}

int	chek_before_lock(t_philo *philo, int i)
{
	pthread_mutex_lock(philo->table->died_flag_mutex);
	if (philo->table->died_flag == 1)
	{
		if (i == 1)
			pthread_mutex_unlock(philo->left_fork);
		else if (i == 2)
			pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->table->died_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->table->died_flag_mutex);
	return (0);
}
