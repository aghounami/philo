/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/22 04:49:46 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(t_philo *philo, char *str)
{
	sem_wait(philo->print_semaphore);
	sem_wait(philo->died_flag_semaphor);
	if (philo->died_flag == 0)
	{
		sem_post(philo->died_flag_semaphor);
		printf("%ld %ld %s", get_time() - philo->start, philo->philo_id, str);
		sem_post(philo->print_semaphore);
	}
	sem_post(philo->print_semaphore);
}

void	ft_usleep(int duration)
{
	long	time_start;

	time_start = get_time();
	while (get_time() - time_start < duration)
	{
		usleep(100);
	}
}
