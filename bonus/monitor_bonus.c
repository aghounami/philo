/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:22:40 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/19 22:47:59 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// int	check_meals(t_philo *philo, int nb_must_eat)
// {
// 	pthread_mutex_lock(philo->table->counter_mutex);
// 	if (philo->meals_counter == nb_must_eat)
// 	{
// 		pthread_mutex_unlock(philo->table->counter_mutex);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(philo->table->counter_mutex);
// 	return (0);
// }

// int	check_death(t_table *table)
// {
// 	int	i;

// 	while (table->died_flag == 0)
// 	{
// 		i = 0;
// 		while (i < table->nb_philo)
// 		{
// 			pthread_mutex_lock(table->philo[i].table->meals_mutex);
// 			if (get_time() - table->philo[i].last_eat > table->time_to_die)
// 			{
// 				pthread_mutex_unlock(table->philo[i].table->meals_mutex);
// 				pthread_mutex_lock(table->died_flag_mutex);
// 				table->died_flag = 1;
// 				ft_print(&table->philo[i], "died\n");
// 				pthread_mutex_unlock(table->died_flag_mutex);
// 				return (1);
// 			}
// 			pthread_mutex_unlock(table->philo[i].table->meals_mutex);
// 			if (check_meals(&table->philo[i], table->nb_must_eat))
// 				return (1);
// 			i++;
// 		}
// 	}
// 	return (0);
// }