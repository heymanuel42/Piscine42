/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:10:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/19 23:17:40 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQ_LIST_H
# define SQ_LIST_H
# include "square.h"

typedef struct s_sq_list{
	t_square	*node;
	t_square	*next;
}t_sq_list;

t_square	*add(t_square *square);
#endif
