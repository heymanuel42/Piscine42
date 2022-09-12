/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:28:09 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/12 15:51:44 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*data;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = min;
	data = (int *)malloc((max - min) * sizeof(int));
	while (i < max)
	{
		data[i - min] = i;
		i++;
	}
	*range = data;
	return (max - min);
}
