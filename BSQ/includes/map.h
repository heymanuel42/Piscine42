/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:42:02 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:37:36 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cell.h"

typedef t_coordinate	t_size;

typedef struct s_map{
	t_size			*dimensions;
	t_cell			***cell;
	char			empty;
	char			obstacle;
	char			fill;
}t_map;

void	draw_map(t_map *map);
t_map	*read_map(const char *file);
void	create_map(t_map *map, t_coordinate at, t_cell *obstacle);
int		free_map(t_map *map);
#endif
