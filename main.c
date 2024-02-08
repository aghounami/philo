/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/08 16:55:11 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    t_data	*data;

    if (ac < 5 || ac > 6)
        return (ft_error("Error: wrong number of arguments\n"));
    data = NULL;
    if (!data)
        return (ft_error("Error: malloc failed\n"));
    if (ft_init_data(data, ac, av))
    {
        free(data);
        return (1);
    }
    // if (ft_init_philo(data))
    // {
    //     free(data->philo);
    //     free(data);
    //     return (1);
    // }
    // if (ft_init_mutex(data))
    // {
    //     ft_destroy_philo(data);
    //     free(data);
    //     return (1);
    // }
    // if (ft_create_threads(data))
    // {
    //     ft_destroy_philo(data);
    //     ft_destroy_mutex(data);
    //     free(data);
    //     return (1);
    // }
    // ft_destroy_philo(data);
    // ft_destroy_mutex(data);
    // free(data);
    return (0);
}
