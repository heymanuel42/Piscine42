/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:28:09 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 09:44:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (data == NULL)
	{
		*range = NULL;
		return (-1);
	}
	while (i < max)
	{
		data[i - min] = i;
		i++;
	}
	*range = data;
	return (max - min);
}
