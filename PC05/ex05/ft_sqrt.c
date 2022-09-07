/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:58:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 19:50:40 by ejanssen         ###   ########.fr       */
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

int	ft_sqrt(int nb)
{
	int n;
	int back;

	back = nb;
	n = 0;
	while(nb > 0)
	{
		n++;
		nb /= 2;
	}
	printf("%d n=%d %d\n",back,n,ft_pow(n,2));
	if(ft_pow(n,2) == back)
		return n;
	else
		return 0;
}
