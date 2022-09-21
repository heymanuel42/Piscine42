/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:33:36 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/21 19:46:57 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bsq/map.h"
#include "includes/ft/ft.h"
#include "includes/bsq/algo.h"
#include "includes/bsq/utils.h"
#include <stdio.h>

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	if (map == NULL)
		return ;
	x = 0;
	y = 0;
	while (y < map->dimensions->y)
	{
		x = 0;
		while (x < map->dimensions->x)
		{
			draw_cell(*(map->cell[y][x]));
			x++;
		}
		y++;
		ft_putstr("\n");
	}
}

void	fill_square(t_map *map, t_square *square)
{
	int	x;
	int	y;

	x = square->coord->x;
	y = square->coord->y;
	while (y < square->coord->y + square->size)
	{
		x = square->coord->x;
		while (x < square->coord->x + square->size)
		{
			map->cell[y - 1][x - 1]->c = map->fill;
			x++;
		}
		y++;
	}
}

int	solve(char *file, int std)
{
	t_map		*map;
	t_square	*sq;

	map = NULL;
	sq = malloc_square(0, 0, 0);
	if (std == 0)
		map = read_map(file, 0);
	else
		map = read_map(file, 1);
	if (map == NULL)
	{
		free_square(sq);
		return (0);
	}
	else
	{
		calc_biggest_square(map, &sq);
		fill_square(map, sq);
		draw_map(map);
		free_map(map);
		free_square(sq);
		return (1);
	}
}

void	solve_from_stdin(void)
{
	int		i;
	char	*buff;
	char	c;

	i = 1;
	c = ' ';
	buff = NULL;
	while (i > 0)
	{
		i = read(STDIN_FILENO, &c, 1);
		buff = append(buff, c);
	}
	buff[i - 1] = '\0';
	ft_putstr("\n");
	if (!solve(buff, 1))
		ft_putstr("map error\n");
	free(buff);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		solve_from_stdin();
	}
	else
	{
		while (i < argc)
		{
			if (!solve(argv[i], 0))
				ft_putstr("map error\n");
			if (i + 1 < argc)
				ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
