/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:27:49 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 16:30:00 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

typedef struct s_pair{
	char	*key;
	char	*value;
}t_pair;

char	*get_key(t_pair *pair);
char	*get_value(t_pair *pair);
void	free_pair(t_pair *pair);
t_pair	*create_pair(char *left, char *right);

#endif
