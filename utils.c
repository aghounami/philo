/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:37:18 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/09 18:28:11 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int parse_args(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if(!(av[i][0]))
			return (1);
		while (av[i][j])
		{
			if(av[i][j] == '+' && j == 0)
				j++;
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void handle_mutex_error(int status, opcode op)


void	safe_mutex_hamdle(mutex *mutex, opcode op)
{
	if (op == LOCK)
		pthread_mutex_lock(mutex);
	else if (op == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (op == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (op == DESTROY)
		pthread_mutex_destroy(mutex);
	else if (op == CREATE)
		pthread_mutex_init(mutex, NULL);
	else if (op == JOIN)
		pthread_mutex_init(mutex, NULL);
	else if (op == DETACH)
		pthread_mutex_init(mutex, NULL);
}
