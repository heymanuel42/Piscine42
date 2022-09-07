/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:31:19 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 12:42:06 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include  <stdio.h>

int	ft_strlen_3(char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_length;
	int	i;

	i = 0;
	dest_length = ft_strlen_3(dest);
	while (nb > 0 && src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
		nb--;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}
