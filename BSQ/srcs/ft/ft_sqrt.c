/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:58:45 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/19 23:09:18 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
	while (nb > 0)
	{
		nb -= i;
		res++;
		i += 2;
	}
	return (res);
}
