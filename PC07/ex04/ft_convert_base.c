/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:54:26 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:54 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		is_in_base(char nb, char*base);
int		base_is_valid(char *base);
int		ft_strlen(char *str);
char	*append(char *str, char a, char *sep);

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

int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 || (nb == 0 && power == 0))
		return (1);
	else
		return (nb * ft_pow(nb, power - 1));
}

int	ft_atoi_base(char *nbr, char *base, int acc, int *sign)
{
	int	power;
	int	base_len;

	base_len = ft_strlen(base);
	power = 0;
	if (*nbr == '\t' || *nbr == '\n' || *nbr == '\v'
		|| *nbr == '\f' || *nbr == '\r' || *nbr == ' ')
		ft_atoi_base(++nbr, base, acc, sign);
	else if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			*sign *= -1;
		ft_atoi_base(++nbr, base, acc, sign);
	}
	else if (is_in_base(*nbr, base) > 0)
	{
		while (is_in_base(nbr[power], base) && nbr[power] != '\0')
			power++;
		acc += get_id_from_base(base, *nbr) * ft_pow(base_len, power - 1);
		return (ft_atoi_base(++nbr, base, acc, sign));
	}
	return (acc);
}

char	*to_base(int nbr, char *base, int sign)
{
	char	*res;
	int		base_length;

	base_length = ft_strlen(base);
	if (sign < 0)
		res = "-";
	else
		res = "";
	if (nbr >= 1)
	{
		res = append(
				to_base(nbr / base_length, base, sign),
				base[nbr % base_length], "");
		return (res);
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	sign;
	int	i_nbr;

	sign = 1;
	if (!base_is_valid(base_from) || !base_is_valid(base_to))
		return (NULL);
	i_nbr = ft_atoi_base(nbr, base_from, 0, &sign);
	if (i_nbr == 0)
		return ("0");
	else
		return (to_base(i_nbr, base_to, sign));
}

/*int	main(int argc, char **argv)
{
	char	*res;

	if (argc == 4)
	{
		res = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("\"%s\" in base(\"%s\") to base(\"%s\") = \"%s\"\n",
		 argv[1], argv[2], argv[3], res);
	}
	return (0);
}*/
