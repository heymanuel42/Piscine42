/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:28:09 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/09 09:42:46 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include
int	ft_ultimate_range(int **range, int min, int max)
{
	int	*range;
	int	i;

	if (min>=max)
		*range = NULL;
	i = min;
	range = (int *)malloc(sizeof(int* ) * (max-min));
	while(i < max)
	{
		range[i-min] = i;
		i++;
	}
	return range;
}
