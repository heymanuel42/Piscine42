/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:58:57 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/15 20:37:25 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	read_file(int argc, char **argv)
{
	int		file_read;

	if (argc == 1)
	{
		ft_putstr(MISSING_FILE, 2);
		return (-1);
	}
	if (argc > 2)
	{
		ft_putstr(TOO_MANY_ARGS, 2);
		return (-1);
	}
	file_read = open(argv[1], O_RDONLY);
	if (file_read < 0)
	{
		ft_putstr(FILE_READ_ERR, 2);
		return (-1);
	}
	return (file_read);
}

int	main(int argc, char **argv)
{
	char	buffer[30000];
	int		fd;
	int		cursor;

	fd = read_file(argc, argv);
	if (fd < 0)
		return (fd);
	read(fd, buffer, 30000);
	cursor = 0;
	while (buffer[cursor] != '\0')
	{
		ft_putchar(buffer[cursor]);
		cursor++;
	}
	close(fd);
	return (0);
}
