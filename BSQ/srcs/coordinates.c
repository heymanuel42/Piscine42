/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:53:32 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:24:55 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/coordinate.h"
#include  "../includes/ft/ft.h"
#include <stdlib.h>

int	distance(t_coordinate c1, t_coordinate c2)
{
	int	x;

	x = ft_pow(c2.x - c1.x, 2) + ft_pow(c2.y - c2.x, 2);
	return (ft_sqrt(x));
}

void	print_coord(t_coordinate coord)
{
	ft_putstr("(");
	ft_putnbr(coord.x);
	ft_putstr(",");
	ft_putnbr(coord.y);
	ft_putstr(")");
}

t_coordinate	*create_coord(int x, int y)
{
	t_coordinate	*coord;

	coord = malloc(sizeof(coord));
	if (coord == NULL)
		return (NULL);
	coord->x = x;
	coord->y = y;
	return (coord);
}

int	free_coord(t_coordinate *coord)
{
	if (coord == NULL)
		return (0);
	free(coord);
	coord = NULL;
	return (1);
}
