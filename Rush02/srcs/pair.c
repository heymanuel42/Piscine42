/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:29:28 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 16:50:28 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pair.h"
#include "../includes/ft/ft.h"
#include <stdlib.h>

char	*get_key(t_pair *pair)
{
	if (pair != NULL)
	{
		if (pair->key != NULL)
			return (pair->key);
		else
			return ("error");
	}
	else
		return ("error");
}

char	*get_value(t_pair *pair)
{
	if (pair != NULL)
	{
		if (pair->value != NULL)
			return (pair->value);
		else
			return ("error");
	}
	else
		return ("error");
}

t_pair	*create_pair(char *left, char *right)
{
	t_pair	*new_pair;

	new_pair = malloc(sizeof(t_pair));
	if (new_pair == NULL)
		return (NULL);
	new_pair->key = ft_strdup(left);
	if (new_pair->key == NULL)
	{
		free(new_pair);
		return (NULL);
	}
	new_pair->value = ft_strdup(right);
	if (new_pair->value == NULL)
	{
		free(new_pair->key);
		free(new_pair);
		return (NULL);
	}
	return (new_pair);
}

void	free_pair(t_pair *pair)
{
	if (pair != NULL)
	{
		if (pair->key != NULL)
			free(pair->key);
		if (pair->value != NULL)
			free(pair->value);
		pair->key = NULL;
		pair->value = NULL;
		free(pair);
		pair = NULL;
	}
}
