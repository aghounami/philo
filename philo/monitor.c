/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:22:40 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/29 04:42:04 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *philo, int nb_must_eat)
{
	pthread_mutex_lock(&philo->table->counter_mutex);
	if (philo->meals_counter >= nb_must_eat && nb_must_eat != -1)
	{
		pthread_mutex_unlock(&philo->table->counter_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->counter_mutex);
	return (0);
}

int	check_death(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		if (check_meals(&table->philo[i], table->nb_must_eat) == 1)
			return (1);
		while (i < table->nb_philo)
		{
			pthread_mutex_lock(&table->philo[i].table->meals_mutex);
			if (get_time() - table->philo[i].last_eat > table->time_to_die)
			{
				pthread_mutex_unlock(&table->philo[i].table->meals_mutex);
				pthread_mutex_lock(&table->print_mutex);
				printf("%ld %d died\n", get_time() - table->philo[i].start,
					table->philo[i].id);
				return (1);
			}
			pthread_mutex_unlock(&table->philo[i].table->meals_mutex);
			i++;
		}
	}
	return (1);
}
