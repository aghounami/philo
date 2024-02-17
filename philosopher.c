/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/17 19:41:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_table(t_table *table, int ac, char **av)
{
    table->died_flag = 0;
    table->died_flag_mutex = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(table->died_flag_mutex, NULL);
    table->nb_philo = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        table->nb_must_eat = ft_atoi(av[5]);
    else
        table->nb_must_eat = -1;
    return 0;
}

int ft_init_philo(t_table *table)
{
    int i;

    for (i = 0; i < table->nb_philo; i++)
    {
        table->philo[i].id = i + 1;
        table->philo[i].meals_counter = 0;
        table->philo[i].last_eat = get_time();
        table->philo[i].start = get_time();
        table->philo[i].left_fork = &table->forks[i];
        table->philo[i].right_fork = &table->forks[(i + 1) % table->nb_philo];
        table->philo[i].table = table;
    }
    if (ft_init_forks(table))
        return 1;
    if (ft_create_threads(table))
        return 1;
    if (ft_join_threads(table))
        return 1;
    return 0;
}

int ft_init_forks(t_table *table)
{
    int i;

    for (i = 0; i < table->nb_philo; i++)
    {
        if (pthread_mutex_init(&table->forks[i], NULL))
            return ft_error("Error: pthread_mutex_init failed\n");
    }
    return 0;
}

int ft_create_threads(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nb_philo)
    {
        if (pthread_create(&table->philo[i].thread, NULL, ft_philo, &table->philo[i]))
            return ft_error("Error: pthread_create failed\n");
        i++;
    }
    return 0;
}

int ft_join_threads(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nb_philo)
    {
        if (pthread_join(table->philo[i].thread, NULL))
            return ft_error("Error: pthread_join failed\n");
        i++;
    }
    return 0;
}

void *ft_philo(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    if (philo->id % 2 != 0)
        usleep(philo->table->time_to_eat * 1000);

    // if (philo->table->nb_philo == 1)
    // {
    //     pthread_mutex_lock(philo->left_fork);
    //     printf("%ld %d has taken a fork\n", get_time() - philo->start, philo->id);
    //     usleep(philo->table->time_to_die * 1000);
    //     printf("%ld %d died\n", get_time() - philo->start, philo->id);
    //     return NULL;
    // }
    while (philo->meals_counter != philo->table->nb_must_eat)
    {
        pthread_mutex_lock(philo->table->died_flag_mutex);
        if (philo->table->died_flag == 1)
        {
            pthread_mutex_unlock(philo->table->died_flag_mutex);
            return NULL;
        }
        pthread_mutex_unlock(philo->table->died_flag_mutex);
        if (ft_take_forks(philo) == 1)
            return NULL;
    }
    return NULL;
}
