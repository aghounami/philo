/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/08 16:56:01 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define FORK 3
# define DEAD 4

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				state;
	long			last_eat;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				philo_done;
	int				dead;
	long			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philos;
}					t_data;

int		ft_atoi(const char *str);
int	ft_error(char *str);
int		ft_strlen(char *s);
int ft_init_data(t_data *data, int ac, char **av);
#endif