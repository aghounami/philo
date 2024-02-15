/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/15 05:03:03 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int ft_take_forks(t_philo *philo) {
    pthread_mutex_lock(&philo->left_fork->mutex);
    printf("%d has taken left fork\n", philo->id);
    pthread_mutex_lock(&philo->right_fork->mutex);
    printf("%d has taken right fork\n", philo->id);
    return 0;
}

int ft_eat(t_philo *philo) {
    printf("%d is eating\n", philo->id);
    usleep(philo->table->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->left_fork->mutex);
    pthread_mutex_unlock(&philo->right_fork->mutex);
    return 0;
}

int ft_sleep(t_philo *philo) {
    printf("%d is sleeping\n", philo->id);
    usleep(philo->table->time_to_sleep * 1000);
    return 0;
}

int ft_think(t_philo *philo) {
    printf("%d is thinking\n", philo->id);
    return 0;
}