/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalumbi <apalumbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:28:41 by apalumbi          #+#    #+#             */
/*   Updated: 2022/09/21 12:24:05 by apalumbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq/map.h"
#include <stdlib.h>

void	free_tab2d(int **tab, t_map *map)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i <= map->dimensions->y)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free (tab);
}

int	**malloc_tab2d(t_map *map)
{
	int	i;
	int	**tab;

	if (map == NULL)
		return (NULL);
	tab = malloc((map->dimensions->y + 1) * sizeof(int *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i <= map->dimensions->y)
	{
		tab[i] = malloc((map->dimensions->x + 1) * sizeof(int));
		if (tab[i] == NULL)
		{
			free_tab2d(tab, map);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

int	build_wall(int **tab, t_map *map)
{
	int		i;

	if (map == NULL)
		return (0);
	if (tab == NULL)
		return (0);
	i = -1;
	while (++i <= map->dimensions->x)
		tab[0][i] = 0;
	i = -1;
	while (++i <= map->dimensions->y)
		tab[i][0] = 0;
	return (1);
}
