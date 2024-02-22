/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/22 04:24:46 by aghounam         ###   ########.fr       */
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
	pthread_mutex_destroy(table->counter_mutex);
	pthread_mutex_destroy(table->meals_mutex);
	pthread_mutex_destroy(table->print_mutex);
	pthread_mutex_destroy(table->died_flag_mutex);
	free(table->died_flag_mutex);
	free(table->counter_mutex);
	free(table->print_mutex);
	free(table->meals_mutex);
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

void	ft_usleep(int duration)
{
	long	time_start;

	time_start = get_time();
	while (get_time() - time_start < duration)
	{
		usleep(10);
	}
}
