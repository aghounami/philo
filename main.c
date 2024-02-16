/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/15 04:58:11 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av) {
    t_philo *philo;

    if (ac < 5 || ac > 6 || parse_args(av))
        return ft_error("Error: wrong arguments\n");

    philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
    if (philo == NULL)
        return ft_error("Error: malloc failed for philosophers\n");

    philo->table = malloc(sizeof(t_table));
    philo->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
    if (philo->table == NULL || philo->forks == NULL) {
        free(philo);
        return ft_error("Error: malloc failed\n");
    }

    if (ft_init_table(philo, ac, av))
        return 1;
    if (ft_init_philo(philo))
        return 1;

    free(philo->table);
    free(philo);

    return 0;
}