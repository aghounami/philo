/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/09 18:00:23 by aghounam         ###   ########.fr       */
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

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
} opcode;
	

typedef pthread_mutex_t mutex;

typedef struct s_fork
{
	mutex	fork;
	int		id_fork;
}				t_fork;


typedef struct s_philo
{
	int				id;
	long			meals_counter;
	bool			full;
	long			last_eat;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	t_table			*table;
}				t_philo;

typedef struct s_table
{
	long			nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_must_eat; //nbr_limit_meals
	long			start_time; //start_simulation
	bool			end_time; //end_simulation
	t_philo			*philo;
	t_fork			*fork;
}				t_table;




int	ft_atoi(const char *str);
int	ft_error(char *str);
int	ft_strlen(char *s);
int	parse_args(int ac, char **av);
#endif