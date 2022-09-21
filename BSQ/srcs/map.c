/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:41:03 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/21 19:56:24 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq/map.h"
#include "../includes/bsq/utils.h"
#include "../includes/ft/ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	get_n_lines(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
		i++;
	return (i);
}

int	map_data_is_valid(char **data, char *subset)
{
	int		n_lines;
	int		actual_lines;
	int		prev_line_len;
	char	*nb;

	nb = substring(data[0], 0, ft_strlen(data[0]) - 3);
	if (get_n_lines(data) == 1)
		return (0);
	actual_lines = 1;
	n_lines = ft_atoi(nb);
	free(nb);
	prev_line_len = ft_strlen(data[actual_lines]);
	while (data[actual_lines] != NULL && !ft_isspace(data[actual_lines]))
	{
		if (!contains(data[actual_lines], subset)
			|| (data[actual_lines] != NULL
				&& prev_line_len != ft_strlen(data[actual_lines])))
			return (0);
		else
			prev_line_len = ft_strlen(data[actual_lines]);
		actual_lines++;
	}
	if (n_lines != actual_lines - 1)
		return (0);
	return (1);
}

t_map	*parse(char **data, char *to_draw, int width, int length)
{
	t_map	*map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = malloc(sizeof(t_map));
	map->fill = to_draw[2];
	map->obstacle = to_draw[1];
	map->empty = to_draw[0];
	map->dimensions = create_coord(width, length);
	map->cell = malloc(sizeof(t_cell ***) * map->dimensions->y);
	while (y < map->dimensions->y)
	{
		map->cell[y] = malloc(sizeof(t_cell **) * map->dimensions->x);
		x = 0;
		while (x < map->dimensions->x)
		{
			map->cell[y][x] = create_cell(data[y + 1][x], y, x);
			x++;
		}
		y++;
	}
	return (map);
}

t_map	*read_map(char *file, int mode)
{
	char	**lines;
	char	*to_draw;
	int		n_lines;
	t_map	*map;
	char	c[3];

	lines = NULL;
	to_draw = NULL;
	map = NULL;
	if (mode == 0)
		lines = read_file(file);
	else
		lines = ft_split(file, "\n");
	if (lines == NULL)
		return (NULL);
	to_draw = header_is_valid(lines[0], &n_lines);
	if (to_draw == NULL)
		return (NULL);
	c[0] = to_draw[0];
	c[1] = to_draw[1];
	c[2] = '\0';
	if (to_draw != NULL && map_data_is_valid(lines, c))
		map = parse(lines, to_draw, ft_strlen(lines[1]), n_lines);
	free_lines(lines);
	return (map);
}

int	free_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (map == NULL)
		return (0);
	while (y < map->dimensions->y)
	{
		x = 0;
		while (x < map->dimensions->x)
		{
			if (map->cell[y][x] != NULL)
				free_cell(map->cell[y][x]);
			x++;
		}
		free(map->cell[y]);
		y++;
	}
	free(map->cell);
	free_coord(map->dimensions);
	free(map);
	map = NULL;
	return (1);
}
