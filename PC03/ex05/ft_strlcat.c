/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:17:37 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/06 12:20:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen_5(char *s)
{
	unsigned int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	int				src_id;
	unsigned int	dest_len;

	dest_len = ft_strlen_5(dest);
	src_id = 0;
	if (dest_len > nb)
		return (dest_len + nb + 2);
	while (src[src_id] != '\0' && ft_strlen_5(dest) < nb - 1)
	{
		dest[dest_len + src_id] = src[src_id];
		src_id++;
	}
	dest[dest_len + src_id] = '\0';
	return (dest_len + ft_strlen_5(src));
}
