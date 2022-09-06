/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:31:02 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 16:51:30 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_check_char(char c)
{
	if (c == ' ')
		return (0);
	if (c == '-')
		return (1);
	if (c == '+')
		return (2);
	if (c >= '0' && c <= '9')
		return (3);

	return (-1);
}

char	*ft_remove_spaces(char *str)
{
	while (ft_check_char(*str) == 0)
		str++;
	return str;
}

char*	ft_get_sign(char *str, int *sign)
{
	int	minus;
	int plus;

	minus = 0;
	plus = 0;
	while (ft_check_char(*str) == 1 || ft_check_char(*str) == 2)
	{
		if (ft_check_char(*str) == 1)
			minus++;
		else if (ft_check_char(*str) == 2)
			plus++;
		str++;
	}
	if(minus % 2 == 0)
		*sign = 1;
	else
		*sign = -1;
	return (str);
}

int ft_pow(int x, int y)
{
	int	res;

	if (y == 0)
		return 1;
	res = x;
	while(y-1 > 0)
	{
		res *=  x;
		y--;
	}
	return (res);
}
int	ft_atoi(char *str)
{
	int sign;
	int idx;
	int res;
	int i;
	
	i = 0;
	res = 0;
	idx = 0;
	str = ft_remove_spaces(str);
	str = ft_get_sign(str, &sign);
	while(str[idx] && ft_check_char(str[idx]) == 3)
		idx++;
	while (i < idx && ft_check_char(str[i] == 3))
	{
		res += (str[i] - '0')  * ft_pow(10,idx - i - 1) ;
		i++;
	}
	return sign * res;
}

int main()
{
	printf("%d\n",ft_atoi("    --+---+1234dd"));
	printf("%d\n",ft_atoi("    --+---+5346dd45"));
	printf("%d\n",ft_atoi("--+--+1234dd"));
	printf("%d\n",ft_atoi("                   --+++-+1234dd"));
	printf("%d\n",ft_atoi("    ++++---+1234dd"));
	printf("%d\n",ft_atoi("    --+---+1234dd"));
	return 0;
}