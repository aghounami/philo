/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/10 22:10:13 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_take_forks(t_table *s)
{
    pthread_mutex_lock(&s->left_fork->mutex);
    printf("%d has taken left fork\n", s->id);
    pthread_mutex_lock(&s->right_fork->mutex);
    printf("%d has taken right fork\n", s->id);
    return (0);
}

long get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
