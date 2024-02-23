/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/23 16:50:50 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_table *table)
{
	table->died_flag_mutex = malloc(sizeof(pthread_mutex_t));
	table->counter_mutex = malloc(sizeof(pthread_mutex_t));
	table->print_mutex = malloc(sizeof(pthread_mutex_t));
	table->meals_mutex = malloc(sizeof(pthread_mutex_t));
	table->start_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->start_mutex, NULL);
	pthread_mutex_init(table->print_mutex, NULL);
	pthread_mutex_init(table->died_flag_mutex, NULL);
	pthread_mutex_init(table->meals_mutex, NULL);
	pthread_mutex_init(table->counter_mutex, NULL);
	return (0);
}

int	ft_init_table(t_table *table, int ac, char **av)
{
	table->died_flag = 0;
	ft_init_mutex(table);
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	else
		table->nb_must_eat = -1;
	if (table->nb_philo == 0 || table->time_to_eat == 0
		|| table->time_to_sleep == 0)
	{
		ft_error("Error: wrong argument\n");
		return (1);
	}
	return (0);
}

int	ft_init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].meals_counter = 0;
		table->philo[i].last_eat = get_time();
		table->philo[i].start = get_time();
		table->philo[i].left_fork = &table->forks[(i + 1) % table->nb_philo];
		table->philo[i].right_fork = &table->forks[i];
		table->philo[i].table = table;
		i++;
	}
	if (ft_init_forks(table))
		return (1);
	if (ft_create_threads(table) == 1)
		return (1);
	if (ft_join_threads(table))
		return (1);
	return (0);
}

int	ft_create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->philo[i].thread, NULL,
				ft_philo, &table->philo[i]))
			return (ft_error("Error: pthread_create failed\n"));
		if (table->time_to_die == 0)
			check_death(table);
		i++;
	}
	check_death(table);
	return (0);
}

int	ft_join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->philo[i].thread, NULL))
			return (ft_error("Error: pthread_join failed\n"));
		i++;
	}
	return (0);
}
