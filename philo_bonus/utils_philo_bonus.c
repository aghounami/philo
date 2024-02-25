/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/25 23:05:19 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(t_philo *philo, char *str)
{
	sem_wait(philo->print);
	printf("%ld %ld %s\n", get_time() - philo->start, philo->philo_id, str);
	sem_post(philo->print);
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
