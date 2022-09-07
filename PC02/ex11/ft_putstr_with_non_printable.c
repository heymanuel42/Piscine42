/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 23:48:53 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 10:29:12 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable_11(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	ft_strlen_11(char *str)
{
	int	length;

	length = 0;
	while (*str++)
	{
		length++;
	}
	return (length);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen_11(str));
}

char	*ft_char_to_hex(char *buff, unsigned char c)
{
	buff[0] = '\\';
	buff[1] = "0123456789abcdef"[c / 16];
	buff[2] = "0123456789abcdef"[c % 16];
	buff[3] = '\0';
	return (buff);
}

void	ft_putstr_with_non_printable(char *str)
{
	char	buff[4];

	while (*str)
	{
		if (!ft_char_is_printable_11(*str))
			ft_putstr(ft_char_to_hex(buff, *str));
		else
			write(1, str, 1);
		str++;
	}
}
