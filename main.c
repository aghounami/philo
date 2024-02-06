/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:32:55 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/06 17:44:41 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int argc, char **av)
{
    t_list *object = malloc(sizeof(t_list));

    if (pars(argc, av) == -1)
    {
        printf("invalid argument\n");
        return -1;
    }
    init_data(&object, av);
    printf("nnn %ld\n", object->number_of_philo);
    return (0);
}
