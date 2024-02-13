/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/13 12:28:41 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_take_forks(t_table *s)
{
    pthread_mutex_lock(&s->left_fork->mutex);
    printf("philo %d has taken left fork\n", s->id);
    pthread_mutex_lock(&s->right_fork->mutex);
    printf("philo %d has taken right fork\n", s->id);
    return (0);
}

