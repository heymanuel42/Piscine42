/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:18:13 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/19 23:35:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/square.h"
#include "../includes/ft/ft.h"
#include <stdlib.h>

t_square	*create_square(int size, int x, int y)
{
	t_square	*square;

	square = malloc(sizeof(square));
	if (square == NULL)
		return (NULL);
	square->size = size;
	square->corner = create_coord(x, y);
	if (square->corner == NULL)
	{
		free(square);
		square = NULL;
		return (NULL);
	}
	return (square);
}

int	free_square(t_square *square)
{
	if (square == NULL)
		return (0);
	if (square->corner != NULL)
		free_coord(square->corner);
	free(square);
	square = NULL;
	return (1);
}

void	print_square(t_square square)
{
	ft_putstr("(");
	ft_putnbr(square.size);
	ft_putstr(",");
	print_coord(*(square.corner));
	ft_putstr(")");
}
