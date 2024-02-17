/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/17 13:05:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    printf("%ld %d has taken a fork\n", get_time() - philo->start, philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("%ld %d has taken a fork\n",get_time() - philo->start, philo->id);
    return 0;
}

int ft_eat(t_philo *philo)
{
    printf("    tiem %ld %d \n", get_time() -  philo->last_eat, philo->id);
    if((get_time() - philo->last_eat > philo->table->time_to_die))
    {
        printf("%ld %d died\n", get_time() - philo->start, philo->id);
        return 1;
    }
    printf("%ld %d is eating\n", get_time() - philo->start, philo->id);
    philo->last_eat = get_time();
    usleep((philo->table->time_to_eat) * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    return 0;
}

int ft_sleep(t_philo *philo)
{
    printf("%ld %d is sleeping\n", get_time() - philo->start, philo->id);
    usleep((philo->table->time_to_sleep) * 1000);
    return 0;
}

int ft_think(t_philo *philo)
{
    printf("%ld %d is thinking\n", get_time() - philo->start, philo->id);
    return 0;
}
