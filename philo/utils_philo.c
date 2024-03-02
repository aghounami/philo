/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/03/02 12:16:36 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mutex(t_table *table, int i)
{
	int	j;

	j = 0;
	if (i == 1)
	{
		while (j < table->nb_philo)
		{
			pthread_mutex_destroy(&table->forks[j]);
			j++;
		}
	}
	pthread_mutex_destroy(&table->counter_mutex);
	pthread_mutex_destroy(&table->meals_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	free(table->philo);
	free(table->forks);
	free(table);
	return (0);
}

int	ft_free(t_table *table)
{
	free(table->philo);
	free(table->forks);
	free(table);
	return (0);
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d %s", get_time() - philo->start, philo->id, str);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	ft_usleep(int duration)
{
	long	time_start;

	time_start = get_time();
	while (get_time() - time_start < duration)
	{
		usleep(10);
	}
}

void	init_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meals_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->table->meals_mutex);
}
