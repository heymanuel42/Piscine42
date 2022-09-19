/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:41:03 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:33:10 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/ft/ft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_map	*read_map(const char *file)
{
	int		fd;
	char	tmp[10000];
	char	**buff;
	int		cursor;
	t_map	*map;
	int		i;
	int		j;
	map = malloc(sizeof(t_map));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read(fd, tmp, 10000);
	buff = ft_split(tmp, "\n");
	while (buff[cursor] != NULL)
		cursor++;
	map->data = buff[0];
	map->dimensions = create_coord(ft_atoi(buff[0]), ft_strlen(buff[1]));
	map->cell = (t_cell ***)malloc(sizeof(t_cell **) * map->dimensions->x);
	i = 0;
	while (i < map->dimensions->x)
	{
		map->cell[i] = malloc(sizeof(t_cell *) * map->dimensions->y);
		j = 0;
		while (j < map->dimensions->y)
		{
			map->cell[i][j] = malloc(sizeof(t_cell));
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < map->dimensions->x)
	{
		j = 0;
		while (j < map->dimensions->y)
		{
			map->cell[i][j] = create_cell(buff[i + 1][j], i, j);
			j++;
		}
		i++;
	}
	while (cursor > 0)
	{
		if (buff[cursor] != NULL)
			free(buff[cursor]);
		cursor--;
	}
	return (map);
}

int	free_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map == NULL)
		return (0);
	while (i < map->dimensions->x)
	{
		j = 0;
		while (j < map->dimensions->y)
		{
			if (map->cell[i][j] != NULL)
			{
				free_cell(map->cell[i][j]);
			}
			j++;
		}
		i++;
	}
	free(map);
	map = NULL;
	return (1);
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	j = 0;
	while (i < map->dimensions->x)
	{
		j = 0;
		while (j < map->dimensions->y)
		{
			draw_cell(*(map->cell[i][j]));
			j++;
		}
		i++;
		ft_putstr("\n");
	}
}
