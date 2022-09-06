/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:38 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/04 16:29:24 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_res(char *str)
{
	if ((str[0] != str[1] && str[0] != str[2] && str[1] != str[2]
			&& (str[0] < str[1] && str[0] < str[2] && str[1] < str[2])))
	{
		write(1, str, 3);
		if (!(str[2] == '9' && str[1] == '8' && str[0] == '7'))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char	str[3];

	str[0] = '0';
	while (!(str[0] == '9' && str[0] == '9' && str[0] == '9'))
	{
		if (str[2] > '9')
		{
			str[2] = '0';
			str[1]++;
			if (str[1] > '9')
			{
				str[1] = '0';
				str[0]++;
			}
		}
		print_res(str);
		str[2]++;
	}
	write(1, "\n", 1);
}
