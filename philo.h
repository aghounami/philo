/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/18 00:58:55 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	long			meals_counter;
	long			last_eat;
	long			start;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				died_flag;
	pthread_mutex_t	*died_flag_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*meals_mutex;
	pthread_mutex_t	*counter_mutex;
	int				nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_must_eat;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_table;

int		chek_before_lock(t_philo *philo, int i);
int		check_death(t_table *table);
int		parse_args(char **av);
int		ft_atoi(const char *str);
int		ft_error(char *str);
int		ft_init_table(t_table *table, int ac, char **av);
int		ft_init_philo(t_table *table);
int		ft_init_forks(t_table *table);
int		ft_create_threads(t_table *table);
int		ft_join_threads(t_table *table);
void	*ft_philo(void *arg);
long	get_time(void);
int		ft_take_forks(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		ft_think(t_philo *philo);
void	ft_print(t_philo *philo, char *str);

#endif
