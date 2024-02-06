/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:44:36 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/06 15:44:51 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long	number_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_times_each_philo_must_eat;
}	t_list;

int	pars(int argc, char **av);
int	init_data(t_list **obj, char **av);
void	exit_error(char *c);
int	ft_isdigit(int c);;

int	check_digit(char *s);

#endif