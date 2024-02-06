/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghounam <aghounam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:08:26 by aghounam          #+#    #+#             */
/*   Updated: 2024/02/06 15:29:13 by aghounam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_digit(char *s)
{
	if (*s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	pars(int argc, char **av)
{
	int i;

	i = 0;
	if (argc > 6 || argc < 5)
        return (-1);
    i = 1;
    while(av[i])
    {
        if (!check_digit(av[i]))
            return (-1);
        i++;
    }
    return (0);
}
