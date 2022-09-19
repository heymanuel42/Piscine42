/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:01:02 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:43:31 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cell.h"
#include "../includes/ft/ft.h"
#include <stdlib.h>

void	draw_cell(t_cell cell)
{
	ft_putchar(cell.c);
}

t_cell	*create_cell(char c, int x, int y )
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	cell->c = c;
	if (cell == NULL)
		return (NULL);
	cell->coord = create_coord(x, y);
	if (cell->coord == NULL)
	{
		free(cell);
		cell = NULL;
		return (NULL);
	}
	return (cell);
}

int	free_cell(t_cell *cell)
{
	if (cell == NULL)
		return (0);
	if (cell->coord != NULL)
	{
		if (free_coord(cell->coord))
			free(cell);
	}
	cell = NULL;
	return (1);
}
