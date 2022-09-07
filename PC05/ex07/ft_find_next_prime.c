/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:07:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/07 22:15:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_2(int nb)
{
	int	n;

	n = 2;
	if (nb == 0 || nb == 1 || nb < 0)
		return (0);
	while (n < nb)
	{
		if ((nb % n) == 0 && n != nb)
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	n;

	n = nb;
	while (!(ft_is_prime_2(n)))
		n++;
	return (n);
}
