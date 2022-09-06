/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:46:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/01 14:33:19 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	r_i;
	int	a;
	int	b;

	a = tab[0];
	b = tab[size - 1];
	i = 0;
	r_i = size - 1;
	while (i < size)
	{
		tab[i] = b;
		tab[r_i] = a;
		i++;
		r_i--;
		a = tab[i];
		b = tab[r_i];
		if (i >= size / 2)
			break ;
	}
}
