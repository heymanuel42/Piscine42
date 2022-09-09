/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:12:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/08 16:24:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min>=max)
		return NULL;
	i = min;
	range = (int *)malloc(sizeof(int* ) * (max-min));
	while(i < max)
	{
		range[i-min] = i;
		i++;
	}
	return range;
}
