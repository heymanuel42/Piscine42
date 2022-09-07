/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:46:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 09:32:18 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_2(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	r_i;

	i = 0;
	r_i = size - 1;
	while (i <= size / 2)
		ft_swap_2(&tab[i++], &tab[r_i--]);
}
