/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:31:33 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/01 15:12:19 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_sorted(int *tab, int size)
{
	int	sorted;
	int	i;

	sorted = -1;
	i = 0;
	while (i < size)
	{
		if (i + 1 < size)
			sorted = tab[i] < tab[i + 1];
		i++;
	}
	return (sorted);
}

int	get_unsorted_smallest(int *tab, int *smallest_index, int offset, int size)
{
	int	i;
	int	smallest;
	int	index;

	smallest = __INT_MAX__;
	index = 0;
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
	int	a;
	int	b;
	int	smallest;
	int	smallest_index;

	a = tab[0];
	smallest = __INT_MAX__;
	smallest_index = 0;
	b = __INT_MAX__;
	offset = 0;
	while (!is_sorted(tab, size))
	{
		a = tab[offset];
		smallest = get_unsorted_smallest(tab, &smallest_index, offset, size);
		tab[offset] = smallest;
		tab[smallest_index] = a;
		offset++;
	}
}
