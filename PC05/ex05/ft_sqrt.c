/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:58:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 22:12:52 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 || (nb == 0 && power == 0))
		return (1);
	else
		return (nb * ft_pow(nb, power - 1));
}

//binary search
int	ft_sqrt(int nb)
{
	int	high;
	int	low;
	int	mid;

	if (nb == 0 || nb == 1)
		return (nb);
	if (nb < 0)
		return (0);
	high = nb;
	low = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}
