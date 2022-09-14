/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:01:47 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 19:16:08 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen_4(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_length;
	int	i;

	i = 0;
	dest_length = ft_strlen_4(dest);
	while (src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}

int	get_final_length(int size, char **strs, char *sep, char **res)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += ft_strlen_4(strs[i]) + ft_strlen_4(sep);
		i++;
	}
	length -= ft_strlen_4(sep);
	if (length > 0)
		*res = malloc(length * sizeof(char));
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		final_length;

	i = 0;
	final_length = get_final_length(size, strs, sep, &res);
	if (final_length <= 0 || res == NULL)
		return (malloc(sizeof(char)));
	while (i < size)
	{
		res = ft_strcat(res, strs[i]);
		if (i != size -1)
			res = ft_strcat(res, sep);
		i++;
	}
	return (res);
}
