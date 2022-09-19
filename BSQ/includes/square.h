/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:38:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/19 23:33:03 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "coordinate.h"

typedef struct s_square{
	int				size;
	t_coordinate	*corner;
}t_square;

int			is_in_square(t_coordinate coord, t_square square);
t_square	*create_square(int size, int x, int y);
int			free_square(t_square *square);
void		print_square(t_square square);
#endif
