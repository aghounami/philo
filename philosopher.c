/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/16 15:46:46 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_init_table(t_philo *philo, int ac, char **av) {
    philo->table->nb_philo = ft_atoi(av[1]);
    philo->table->time_to_die = ft_atoi(av[2]);
    philo->table->time_to_eat = ft_atoi(av[3]);
    philo->table->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo->table->nb_must_eat = ft_atoi(av[5]);
    else
        philo->table->nb_must_eat = -1;

    return 0;
}

int ft_init_philo(t_philo *philo) {
    int i;

    for (i = 0; i < philo->table->nb_philo; i++) {
        philo[i].id = i + 1;
        philo[i].meals_counter = 0;
        philo[i].last_eat = 3;
        philo[i].left_fork = &philo->table->forks[i];
        if(i == philo->table->nb_philo - 1)
            philo[i].right_fork = &philo->table->forks[0];
        else
            philo[i].right_fork = &philo->table->forks[i + 1];
    }
    // if(ft_init_forks(philo))
    //     return 1;
    // if (ft_create_threads(philo))
    //     return 1;
    // if (ft_join_threads(philo))
    //     return 1;
    ft_philo(&philo);
    
    return 0;
}

int ft_init_forks(t_philo *philo) {
    int i;

    for (i = 0; i < philo->table->nb_philo; i++) {
        if (pthread_mutex_init(&philo->right_fork[i], NULL))
            return ft_error("Error: pthread_mutex_init failed\n");
    }
    return 0;
}

int ft_create_threads(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->table->nb_philo)
    {
        if (pthread_create(&philo[i].thread, NULL, ft_philo, &philo[i]))
            return (ft_error("Error: pthread_create failed\n"));
        i++;
    }
    return (0);
}

int ft_join_threads(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->table->nb_philo)
    {
        if (pthread_join(philo[i].thread, NULL))
            return (ft_error("Error: pthread_join failed\n"));
        i++;
    }
    return (0);
}
void *ft_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    // while (1)
    // {
        ft_take_forks(philo);
        // ft_eat(philo);
        // ft_sleep(philo);
        // ft_think(philo);
    // }
    return (NULL);
}

