/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:22:40 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/25 23:30:50 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (get_time() - philo->last_eat > philo->time_to_die)
		{
			sem_wait(philo->print);
			printf("%ld %ld died\n", get_time() - philo->start, \
				philo->philo_id);
			exit (1);
		}
		if (philo->nb_must_eat != -1 && philo->counter >= philo->nb_must_eat)
			exit (0);
	}
	return (NULL);
}
