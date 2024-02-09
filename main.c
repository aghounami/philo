/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/09 16:36:26 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int main(int ac, char **av)
{
	t_table table;

	if (ac < 5 || ac > 6 || parse_args(ac, av))
		return (ft_error("Error: wrong in arguments\n"));
	if(ft_init_table(table, ac, av))
		return (1);
	init_philo(table);
	
	return (0);
}