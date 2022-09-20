/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:59:37 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 22:01:01 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/ft/ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*append(char *str, char a)
{
	char	*res;
	int		length;
	int		i;

	if (str == NULL)
		str = malloc(sizeof(char));
	length = ft_strlen(str) + 2;
	res = malloc(length * sizeof(char));
	i = 0;
	while (str[i] != '\0')
	{
			res[i] = str[i];
			i++;
	}
	res[i] = a;
	res[i + 1] = '\0';
	if (*str != '\0' )
		free(str);
	return (res);
}

char	**read_file(const char *file)
{
	char	*content;
	char	curr;
	char	**lines;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = NULL;
	curr = ' ';
	while (read(fd, &curr, 1))
		content = append(content, curr);
	lines = ft_split(content, "\n");
	free(content);
	if (close(fd) < 0)
		return (NULL);
	return (lines);
}

void	free_lines(char **lines)
{
	int		i;

	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
}

int	contains(char *str, char *c)
{
	int	i;
	int	j;
	int	has;

	has = 0;
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		has = 0;
		while (j < 3)
		{
			if (str[i] == c[j])
				has = 1;
			j++;
		}
		if (!has)
			return (0);
		i++;
	}
	return (has);
}
