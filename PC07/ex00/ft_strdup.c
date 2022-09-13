/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:11:39 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/12 15:49:15 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen1(char *s1)
{
	int	length;

	length = 0;
	while (s1[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	char	*start;

	cpy = malloc(ft_strlen1(src) * sizeof(char));
	start = cpy;
	while (*src)
	{
		*cpy = *src;
		src++;
		cpy++;
	}
	cpy = start;
	return (cpy);
}