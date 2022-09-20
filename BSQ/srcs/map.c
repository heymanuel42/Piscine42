/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:41:03 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 22:03:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/utils.h"

#include "../includes/ft/ft.h"
#include <stdlib.h>
#include <unistd.h>

char	*header_is_valid(char *header, int *length)
{
	*length = ft_atoi(header);
	if (*header == '+' || *header == '-' || *length <= 0)
		return (NULL);
	while (*header >= '0' && *header <= '9')
		header++;
	if (ft_strlen(header) != 3)
		return (NULL);
	if (header[0] == header[1]
		|| header[1] == header[2]
		|| header[0] == header[2])
		return (NULL);
	return (header);
}

int	map_data_is_valid(char **data, char *subset)
{
	int	n_lines;
	int	actual_lines;
	int	prev_line_len;

	actual_lines = 1;
	n_lines = ft_atoi(data[0]);
	prev_line_len = ft_strlen(data[actual_lines]);
	while (data[actual_lines] != NULL)
	{
		if (!contains(data[actual_lines], subset))
			return (0);
		if (data[actual_lines] != NULL
			&& prev_line_len != ft_strlen(data[actual_lines]))
			return (0);
		else
			prev_line_len = ft_strlen(data[actual_lines]);
		actual_lines++;
	}
	if (n_lines != actual_lines - 1)
		return (0);
	actual_lines = 0;
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
	map->cell = (t_cell ***)malloc(sizeof(t_cell **) * map->dimensions->y);
	while (y < map->dimensions->y)
	{
		map->cell[y] = malloc(sizeof(t_cell *) * map->dimensions->x);
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

t_map	*read_map(const char *file)
{
	char	**lines;
	char	*to_draw;
	int		n_lines;
	t_map	*map;

	map = NULL;
	lines = read_file(file);
	to_draw = header_is_valid(lines[0], &n_lines);
	if (to_draw != NULL && map_data_is_valid(lines, to_draw))
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
			{
				free_cell(map->cell[y][x]);
			}
			x++;
		}
		y++;
	}
	free(map->dimensions);
	free(map->cell);
	free(map);
	map = NULL;
	return (1);
}
