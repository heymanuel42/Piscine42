/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:36:53 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:44:00 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H

# include "coordinate.h"

typedef enum e_type{
	EMPTY = 0,
	OBSTACLE = 1,
	FILLED = 2
}t_type;

typedef struct s_cell{
	t_type			type;
	char			c;
	t_coordinate	*coord;
}t_cell;

void	draw_cell(t_cell cell);
t_cell	*create_cell(char c, int x, int y );
int		free_cell(t_cell *cell);

#endif
