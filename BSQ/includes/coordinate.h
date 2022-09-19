/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:37:10 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:24:34 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_H
# define COORDINATE_H

typedef struct s_coordinate{
	int	x;
	int	y;
}t_coordinate;

int				distance(t_coordinate c1, t_coordinate c2);
void			print_coord(t_coordinate coord);
t_coordinate	*create_coord(int x, int y);
int				free_coord(t_coordinate *coord);
#endif
