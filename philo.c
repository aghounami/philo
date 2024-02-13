/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/13 20:30:29 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork->mutex);
    printf("%d has taken a fork\n", philo->id);
    pthread_mutex_lock(&philo->right_fork->mutex);
    printf("%d has taken a fork\n", philo->id);
    // printf("%d is eating", philo->id);
    return (0);
}

int ft_eat(t_philo *philo)
{
    printf("%d is eating", philo->id);
    return (0);
}

int ft_sleep(t_philo *philo)
{
    printf("%d is sleeping", philo->id);
    return (0);
}
int ft_think(t_philo *philo)
{
    printf("%d is thinking", philo->id);
    return (0);
}
