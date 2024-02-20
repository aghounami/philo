/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:23 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/20 20:29:42 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				*id;
	long			meals_counter;
	long			last_eat;
	long			start;
	int				died_flag;
	// pthread_t		thread;
	sem_t			*died_flag_mutex;
	sem_t			*print_mutex;
	sem_t			*meals_mutex;
	sem_t			*counter_mutex;
	sem_t			*forks;
	int				nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_must_eat;
	long            nb_forks;
	long			philo_id;
	pthread_t		check_monitor;
	// sem_t			*right_fork;
	// sem_t			*left_fork;
	// struct s_table	*table;
}	t_philo;

void	*ft_philo(t_philo *philo);
int		ft_init_table(t_philo *table, int ac, char **av);
int		ft_init_process(t_philo *table);
void	ft_usleep(int duration);
int		parse_args(char **av);
int		ft_atoi(const char *str);
int		ft_error(char *str);
long	get_time(void);
int		ft_take_forks(t_philo *philo);
int		ft_eat(t_philo *philo);
int		ft_sleep(t_philo *philo);
int		ft_think(t_philo *philo);
void	ft_print(t_philo *philo, char *str);

#endif
