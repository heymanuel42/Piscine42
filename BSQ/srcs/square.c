/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:23:12 by apalumbi          #+#    #+#             */
/*   Updated: 2022/09/20 19:35:21 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq/square.h"

t_square	*malloc_square(int size, int x, int y)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (square == NULL)
		return (NULL);
	square->size = size;
	square->coord = create_coord(x, y);
	if (square->coord == NULL)
	{
		free_square(square);
		return (NULL);
	}
	return (square);
}

/* t_square	**malloc_square(int size, int x, int y)
{
	t_square	**square;

	*square = malloc(sizeof(t_square *));
	if (square == NULL)
		return (NULL);
	square->size = size;
	square->coord = create_coord(x, y);
	if (square->coord == NULL)
	{
		free_square(square);
		return (NULL);
	}
	return (square);
} */

void	free_square(t_square *square)
{
	if (square != NULL)
	{
		free_coord(square->coord);
		free(square);
	}
}

/* t_square	*ud_s(int size, int x, int y)
{
	t_square	*square;

	square = malloc_square(size, x, y);
	if (square == NULL)
		return (NULL);
	return (square);
} */
