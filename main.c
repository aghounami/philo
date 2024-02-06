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
    t_list  *object = NULL;

    if(pars(argc, av));
        return (1);
    int_data(&object, av);
    return (0);
}
