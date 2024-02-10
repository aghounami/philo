/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/10 22:20:52 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_table(t_all *s, int ac, char **av)
{
	s->table = malloc(sizeof(t_table));
	s->table->nb_philo = ft_atoi(av[1]);
	s->table->time_to_die = ft_atoi(av[2]);
	s->table->time_to_eat = ft_atoi(av[3]);
	s->table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		s->table->nb_must_eat = ft_atoi(av[5]);
	else
		s->table->nb_must_eat = -1;
	s->philo = malloc(sizeof(t_table) * s->table->nb_philo);
	s->fork = malloc(sizeof(t_fork) * s->table->nb_philo);
	if (!s->philo || !s->fork)
		return (ft_error("Error: malloc failed\n"));
	return (0);
}

int ft_init_philo(t_all *s)
{
    int i;

    i = 0;
    while (i < s->table->nb_philo)
    {
        s->philo[i].id = i + 1;
        s->philo[i].meals_counter = 0;
        s->philo[i].full = false;
        s->philo[i].last_eat = 0;
        s->philo[i].left_fork = &s->fork[i];
        if (i == s->table->nb_philo - 1)
            s->philo[i].right_fork = &s->fork[0];
        else
            s->philo[i].right_fork = &s->fork[i + 1];
        i++;
		s->philo[i].start = get_time();
    }
    return (0);
}

int ft_init_forks(t_all *s)
{
	int i;

	i = 0;
	while (i < s->table->nb_philo)
	{
		if (pthread_mutex_init(&s->fork[i].mutex, NULL))
			return (ft_error("Error: pthread_mutex_init failed\n"));
		i++;
	}
	return (0);
}

int ft_create_threads(t_all *s)
{
	int i;

	i = 0;
	while (i < s->table->nb_philo)
	{
		if (pthread_create(&s->philo[i].thread, NULL, ft_philo, &s->philo[i]))
			return (ft_error("Error: pthread_create failed\n"));
		i++;
	}
	return (0);
}

int ft_join_threads(t_all *s)
{
	int i;

	i = 0;
	while (i < s->table->nb_philo)
	{
		if (pthread_join(s->philo[i].thread, NULL))
			return (ft_error("Error: pthread_join failed\n"));
		i++;
	}
	return (0);
}

void *ft_philo(void *arg)
{
	t_all *s = (t_all *)malloc(sizeof(t_all));

	s->table = (t_table *)arg;
	while (1)
		if(s->table->id % 2 == 0)
			ft_take_forks(s->table);
	{
		sleep(1);
		// ft_eat(s->table);
		// ft_sleep(s->table);
		// ft_think(s->table);
	}
	return (NULL);
}

