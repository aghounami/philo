/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:22:40 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/23 16:53:37 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_meals(t_philo *philo, int nb_must_eat)
{
	if (philo->counter == nb_must_eat)
	{
		return (1);
	}
	return (0);
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->died_flag == 0)
	{
		usleep(1000);
		if (philo->died_flag == 1)
			break ;
		if (get_time() - philo->last_eat > philo->time_to_die && \
			philo->died_flag == 0)
		{
			sem_wait(philo->print_semaphore);
			if (philo->died_flag == 1)
				break ;
			philo->died_flag = 1;
			printf("%ld %ld died\n", get_time() - philo->start, \
				philo->philo_id);
			exit(1);
			sem_post(philo->print_semaphore);
		}
		usleep(1000);
		if (check_meals(philo, philo->nb_must_eat))
			break ;
	}
	exit(0);
}
