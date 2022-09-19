/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:32:36 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/19 23:35:46 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 || (nb == 0 && power == 0))
		return (1);
	else
		return (nb * ft_pow(nb, power - 1));
}
