/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:11:39 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 11:55:34 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen1(char *s1)
{
	int	length;

	length = 0;
	while (s1[length] != '\0')
		length++;
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (start);
}

char	*ft_strdup(char *src)
{
	char	*cpy;

	cpy = malloc(ft_strlen1(src) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	return (ft_strcpy(cpy, src));
}
