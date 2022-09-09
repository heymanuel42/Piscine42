/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:07:14 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/09 11:43:53 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	res;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	res = nb;
	n = nb - 1;
	while (n > 0)
	{
		res *= n;
		n--;
	}
	return (res);
}
