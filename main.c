/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/13 20:27:34 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_all *s;

	s = malloc(sizeof(t_all));
    if (s == NULL)
        return ft_error("Error: malloc failed\n");
	if (ac < 5 || ac > 6 || parse_args(av))
		return (ft_error("Error: wrong in arguments\n"));
	if(ft_init_table(s, ac, av))
		return (1);
	if (ft_init_philo(s))
		return (1);
	if (ft_init_forks(s))
		return (1);
	if (ft_create_threads(s))
		return (1);
	// if (ft_join_threads(s))
		// return (1);
	// if (ft_destroy_mutex(s))
		// return (1);
	free(s->philo);
	free(s->fork);
	free(s);
	return (0);
}