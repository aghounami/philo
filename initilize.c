/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:02 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/06 18:18:01 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ini_data(t_list *obj, char **av)
{
	obj->number_of_philo = atoi(av[1]);
	obj->time_to_die = atoi(av[2]);
	obj->time_to_eat = atoi(av[3]);
	obj->time_to_sleep = atoi(av[4]);
	if(av[5])
		obj->number_of_times_each_philo_must_eat = atoi(av[5]);
}