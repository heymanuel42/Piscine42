/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:50:49 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/16 11:00:18 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_contains(char **str, char *to_find, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_strcmp(str[i], to_find))
			return (i);
		i++;
	}
	return (-1);
}
