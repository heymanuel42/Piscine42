/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:54:26 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/11 16:59:27 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_id_from_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 || (nb == 0 && power == 0))
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_atoi_base(char *c, char *base, int p, int acc)
{
	int	res;
	int	i;

	if (*c == '\0')
		return (0);
	else
	{
		i = get_id_from_base(base,*c);
		res = acc + i * ft_recursive_power(10, i-2);
		printf("%d %d %d\n", i, res, acc);
		ft_atoi_base(++c, base, p++, res);
		return (res);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return " ";
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_atoi_base(argv[1], "0123456789", 0, 0));
	}
	return (0);
}
