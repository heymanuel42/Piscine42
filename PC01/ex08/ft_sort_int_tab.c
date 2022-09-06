/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:31:33 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/06 23:16:24 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap_3(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sorted(int *tab, int size)
{
	int	sorted;
	int	i;

	sorted = -1;
	i = 0;
	while (i < size)
	{
		if( tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (sorted);
}

int	get_unsorted_smallest(int *tab, int *smallest_index, int offset, int size)
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
			*smallest_index = i;
		}
		i++;
	}
	return (smallest);
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

