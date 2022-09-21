/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:28:59 by apalumbi          #+#    #+#             */
/*   Updated: 2022/09/21 19:45:53 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq/tab2d.h"
#include "../includes/bsq/algo.h"
#include "../includes/ft/ft.h"
#include <stdio.h>

int	min(int pos1, int pos2, int pos3)
{
	if (pos1 <= pos2 && pos1 <= pos3)
		return (pos1 + 1);
	else if (pos2 <= pos1 && pos2 <= pos3)
		return (pos2 + 1);
	else
		return (pos3 + 1);
}

int	**update_tab(t_map *map, int **t, t_square **s, t_coordinate *coord)
{
	int	x;
	int	y;

	x = coord->x;
	y = coord->y;
	if (map->cell[y - 1][x - 1]->c == map->obstacle)
		(t[y][x]) = 0;
	else
	{
		(t[y][x]) = min((t[y][x - 1]), (t[y - 1][x - 1]), (t[y - 1][x]));
		if ((t[y][x]) > (*s)->size)
		{
			(*s)->size = (t[y][x]);
			(*s)->coord->x = x - (*s)->size + 1;
			(*s)->coord->y = y - (*s)->size + 1;
		}
	}
	return (t);
}

int	**config_wall(t_map *map, t_coordinate **coord)
{
	int	success;
	int	**tab;

	success = 1;
	if (map == NULL)
		success = 0;
	tab = malloc_tab2d(map);
	if (tab == NULL)
		success = 0;
	*coord = malloc(sizeof(t_coordinate *));
	if (*coord == NULL)
		success = 0;
	if (!build_wall(tab, map))
		success = 0;
	if (!success)
	{
		free_tab2d(tab, map);
		free_map(map);
		free_coord(*coord);
	}
	return (tab);
}

void	calc_biggest_square(t_map *map, t_square **s)
{
	int				y;
	int				x;
	int				**t;
	t_coordinate	*coord;

	t = config_wall(map, &coord);
	y = 1;
	x = 1;
	while (y <= map->dimensions->y)
	{
		x = 0;
		while (++x <= map->dimensions->x)
		{
			coord->x = x;
			coord->y = y;
			t = update_tab(map, t, s, coord);
		}
		y++;
	}
	free_coord(coord);
	free_tab2d(t, map);
}
