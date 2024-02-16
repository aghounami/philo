/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/16 15:30:25 by aghounam         ###   ########.fr       */
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


typedef struct s_table
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_must_eat;
    pthread_mutex_t *forks;
} t_table;

typedef struct s_philo
{
    int id;
    int meals_counter;
    long last_eat;
    t_table *table;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_t thread;
} t_philo;

int ft_error(char *str);
int ft_init_table(t_philo *philo, int ac, char **av);
int ft_init_philo(t_philo *philo);
int ft_init_forks(t_philo *philo);
int ft_create_threads(t_philo *philo);
int ft_join_threads(t_philo *philo);
void *ft_philo(void *arg);
int ft_atoi(const char *str);
int parse_args(char **av);
long get_time(void);
int ft_sleep(t_philo *philo);
int ft_think(t_philo *philo);
int ft_take_forks(t_philo *philo);
int ft_eat(t_philo *philo);

#endif
