/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/17 19:39:02 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->table->died_flag_mutex);
    if (philo->table->died_flag == 1)
    {
        pthread_mutex_unlock(philo->table->died_flag_mutex);
        return 1;
    }
    pthread_mutex_unlock(philo->table->died_flag_mutex); 
    pthread_mutex_lock(philo->left_fork);
    printf("%ld %d has taken a fork\n", get_time() - philo->start, philo->id);
    pthread_mutex_lock(philo->right_fork);
    printf("%ld %d has taken a fork\n",get_time() - philo->start, philo->id);
    if (ft_eat(philo) == 1)
        return 1;
    if (ft_sleep(philo) == 1)
        return 1;
    if(ft_think(philo) == 1)
        return 1;
    if (philo->table->nb_must_eat != -1)
            philo->meals_counter++;
    return 0;
}

int ft_eat(t_philo *philo)
{
    if (check_death(philo) == 1)
        return 1;
    printf("%ld %d is eating\n", get_time() - philo->start, philo->id);
    philo->last_eat = get_time();
    usleep((philo->table->time_to_eat) * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    return 0;
}

int ft_sleep(t_philo *philo)
{
    pthread_mutex_lock(philo->table->died_flag_mutex);
    if (philo->table->died_flag == 1)
    {
        pthread_mutex_unlock(philo->table->died_flag_mutex);
        return 1;
    }
    pthread_mutex_unlock(philo->table->died_flag_mutex); 
    printf("%ld %d is sleeping\n", get_time() - philo->start, philo->id);
    usleep((philo->table->time_to_sleep) * 1000);
    return 0;
}

int ft_think(t_philo *philo)
{
    pthread_mutex_lock(philo->table->died_flag_mutex);
    if (philo->table->died_flag == 1)
    {
        pthread_mutex_unlock(philo->table->died_flag_mutex);
        return 1;
    }
    pthread_mutex_unlock(philo->table->died_flag_mutex); 
    printf("%ld %d is thinking\n", get_time() - philo->start, philo->id);
    return 0;
}

int check_death(t_philo *philo) {
    pthread_mutex_lock(philo->table->died_flag_mutex);
    if (get_time() - philo->last_eat > philo->table->time_to_die)
    {
        printf("%ld %d died\n", get_time() - philo->start, philo->id);
        (philo->table->died_flag) = 1; // Set the died flag
        pthread_mutex_unlock(philo->table->died_flag_mutex);
        return 1;
    }
    pthread_mutex_unlock(philo->table->died_flag_mutex);
    return 0;
}
