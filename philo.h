/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/10 22:07:15 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

typedef struct s_fork
{
    pthread_mutex_t mutex;
} t_fork;

typedef struct s_table
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_must_eat;
    int id;
    int meals_counter;
    bool full;
    long last_eat;
    t_fork *left_fork;
    t_fork *right_fork;
    pthread_t thread;
    long start;
    long end;
    long time;
} t_table;

typedef struct s_all
{
    t_table *table;
    t_table *philo;
    t_fork *fork;
} t_all;

int ft_atoi(const char *str);
int	ft_error(char *str);
int	ft_init_table(t_all *s, int ac, char **av);
int ft_init_forks(t_all *s);
int ft_init_philo(t_all *s);
int ft_create_threads(t_all *s);
void *ft_philo(void *arg);
int ft_join_threads(t_all *s);
int ft_destroy_mutex(t_all *s);
int parse_args(char **av);
long get_time(void);
void ft_usleep(long time);
int ft_take_forks(t_table *s);

#endif