/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:20:16 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 17:07:20 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H

# include "pair.h"

typedef struct s_dict{
	t_pair			*pair;
	struct s_dict	*next;
	struct s_dict	*parent;
}t_dict;

t_dict	*find(t_dict *dict, const char *s);
t_dict	*add(t_dict **dict, t_pair *pair);
void	free_dict(t_dict *dict);
t_dict	*create_entry(t_pair *pair, t_dict *parent, t_dict *next);
char	*get_dict_value(t_dict *dict, const char *key);

t_dict	*g_dictionnary;
#endif
