/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:33:36 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 22:03:55 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"
#include "includes/ft/ft.h"
#include <stdlib.h>

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

int	main(int argc, char**argv)
{
	t_map	*map;

	(void)argc;
	map = read_map(argv[1]);
	if (map != NULL)
	{
		draw_map(map);
		ft_putstr("\n");
		ft_putstr("empty : ");
		ft_putchar(map->empty);
		ft_putstr("\n");
		ft_putstr("filled : ");
		ft_putchar(map->fill);
		ft_putstr("\n");
		ft_putstr("obstacle : ");
		ft_putchar(map->obstacle);
		ft_putstr("\n");
		free_map(map);
	}
	return (0);
}
