/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:58:57 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/16 09:27:36 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils.h"

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
	char	buffer[BUFFER_SIZE];
	int		fd;
	int		cursor;

	fd = read_file(argc, argv);
	if (fd < 0)
		return (fd);
	read(fd, buffer, BUFFER_SIZE);
	cursor = 0;
	while (buffer[cursor] != '\0')
	{
		ft_putchar(buffer[cursor]);
		cursor++;
	}
	close(fd);
	return (0);
}
