/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:31:33 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 09:32:24 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap_3(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	get_unsorted_smallest(int *tab, int *sid, int offset, int size)
{
	int	i;
	int	smallest;

	smallest = __INT_MAX__;
	i = offset;
	while (i < size)
	{
		if (tab[i] < smallest)
		{
			smallest = tab[i];
			*sid = i;
		}
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	offset;
	int	smallest_index;

	smallest_index = 0;
	offset = 0;
	while (!is_sorted(tab, size))
	{
		get_unsorted_smallest(tab, &smallest_index, offset, size);
		ft_swap_3(&tab[offset], &tab[smallest_index]);
		offset++;
	}
}
