/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:01:47 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/10 12:23:49 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen_4(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*append(char *str, char *a, char *sep)
{
	char	*res;
	int		length;
	int		i;

	length = ft_strlen_4(str) + ft_strlen_4(a) + ft_strlen_4(sep);
	res = malloc(length * sizeof(char));
	i = 0;
	if (ft_strlen_4(str) > 0)
	{
		while (*str != '\0')
			res[i++] = *(str++);
		while (*sep != '\0')
			res[i++] = *(sep++);
	}
	while (*a != '\0')
		res[i++] = *(a++);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	if (size <= 0)
	{
		res = malloc(1);
		res = "";
		return (0);
	}
	i = 1;
	res = append("", strs[0], sep);
	while (i < size)
	{
		res = append(res, strs[i], sep);
		i++;
	}
	return (res);
}
