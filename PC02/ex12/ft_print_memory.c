/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:34:42 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 10:19:31 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

const unsigned int	g_base = 16;
const char			g_hex[16] = "0123456789abcdef";

void	ft_put_addr_to_str(long unsigned int addr, int length, int init)
{
	if (length - 1 > 0)
	{
		ft_put_addr_to_str(addr / g_base, --length, 0);
		ft_put_addr_to_str(addr % g_base, 0, 0);
	}
	else
	{
		if (addr > 0)
			write(1, &g_hex[addr], 1);
		else
			write(1, "0", 1);
	}
	if (init == 1)
	{
		write(1, ":", 1);
	}
}

void	ft_put_as_hex(void *addr, unsigned int length)
{
	char			buff[3];
	char			c;
	unsigned int	n;

	n = 0;
	while (n < length)
	{
		if (n % 2 == 0)
			write(1, " ", 1);
		c = *(int *)(addr + n++);
		buff[0] = g_hex[c / g_base];
		buff[1] = g_hex[c % g_base];
		buff[2] = '\0';
		write(1, buff, 3);
	}
	while (n < 16)
	{
		if (n % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		n++;
	}
}

void	put_line(void *addr, unsigned int length)
{
	unsigned int	n;
	char			c;

	ft_put_addr_to_str((unsigned long int)addr, g_base, 1);
	ft_put_as_hex(addr, length);
	write(1, " ", 1);
	n = 0;
	while (n < length)
	{
		c = *(char *)(addr + n++);
		if (!(c >= 32 && c <= 126))
			write(1, ".", 1);
		else
			write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				nb_lines;
	int				rest;

	i = 0;
	nb_lines = size / 16;
	rest = size % 16;
	if (size > 0)
	{
		while (nb_lines > 0)
		{
			put_line(addr + i, 16);
			i += 16;
			nb_lines--;
		}
		if (rest > 0)
			put_line(addr + i, rest);
	}
	return (addr);
}
