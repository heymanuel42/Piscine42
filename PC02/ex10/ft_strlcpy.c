/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:14:42 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 10:17:30 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*start;

	start = src;
	if (size > 0)
	{
		while (size - 1 > 0 && *src)
		{
			*dest++ = *src++;
			size--;
		}
	}
	while (*src++)
		;
	if (size > 0)
		*dest = '\0';
	return (src - start - 1);
}
