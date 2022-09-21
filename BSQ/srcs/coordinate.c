/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:53:32 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 10:40:28 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq/coordinate.h"
#include  "../includes/ft/ft.h"
#include <stdlib.h>

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
