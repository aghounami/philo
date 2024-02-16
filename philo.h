/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/16 21:47:00 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <limits.h>


typedef struct s_philo
{
    int id;
    useconds_t meals_counter;
    long last_eat;
    pthread_t thread;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    struct s_table *table;
} t_philo;

typedef struct s_table
{
    int nb_philo;
    // int nb_must_eat;
    useconds_t time_to_die;
    useconds_t time_to_eat;
    useconds_t time_to_sleep;
    useconds_t nb_must_eat;
    pthread_mutex_t *forks;
    t_philo *philo;
} t_table;

int parse_args(char **av);
int ft_atoi(const char *str);
int ft_error(char *str);
int ft_init_table(t_table *table, int ac, char **av);
int ft_init_philo(t_table *table);
int ft_init_forks(t_table *table);
int ft_create_threads(t_table *table);
int ft_join_threads(t_table *table);
void *ft_philo(void *arg);
long get_time(void);
int ft_take_forks(t_philo *philo);
int ft_eat(t_philo *philo);
int ft_sleep(t_philo *philo);
int ft_think(t_philo *philo);

#endif
