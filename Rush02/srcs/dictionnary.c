/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:26:15 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 17:07:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dictionnary.h"
#include "../includes/ft/ft.h"
#include <stdlib.h>

t_dict	*find(t_dict *dict, const char *key)
{
	t_dict	*current;

	if (dict == NULL)
		return (NULL);
	current = dict;
	while (current->next != NULL)
	{
		if (!ft_strcmp(get_key(current->pair), key))
			return (current);
		current = current->next;
	}
	return (current);
}

char	*get_dict_value(t_dict *dict, const char *key)
{
	t_dict	*found;

	found = find(dict, key)->next;
	if (found == NULL)
		return ("error");
	else
		return (get_value(found->pair));
}

t_dict	*create_entry(t_pair *pair, t_dict *parent, t_dict *next)
{
	t_dict	*entry;

	entry = malloc(sizeof(t_dict));
	if (entry == NULL)
		return (NULL);
	entry->pair = pair;
	entry->parent = parent;
	entry->next = next;
	return (entry);
}

t_dict	*add(t_dict **dict, t_pair *pair)
{
	t_dict	*entry;

	if (*dict == NULL)
	{
		*dict = create_entry(pair, NULL, NULL);
		return (*dict);
	}
	else
	{
		entry = find(*dict, get_key(pair));
		if (entry != NULL
			&& entry->pair != NULL
			&& !ft_strcmp(get_key(entry->pair), get_key(pair)))
		{
			free_pair(entry->pair);
			entry->pair = pair;
		}
		else if (entry->next == NULL)
			entry->next = create_entry(pair, entry, NULL);
	}
	return (entry->next);
}

void	free_dict(t_dict *dict)
{
	while (dict != NULL)
	{
		free_pair(dict->pair);
		if (dict->parent != NULL)
			free(dict->parent);
		dict = dict->next;
	}
}
