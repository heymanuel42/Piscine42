/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:59:37 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/21 19:56:35 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq/utils.h"
#include "../includes/ft/ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*header_is_valid(char *header, int *length)
{
	int		i;
	char	*nb;

	nb = substring(header, 0, ft_strlen(header) - 3);
	i = ft_strlen(header) - 1;
	if (header[i] == header[i - 1]
		|| header[i - 1] == header[i - 2]
		|| header[i] == header[i - 2])
		return (NULL);
	*length = ft_atoi(nb);
	free(nb);
	if (*header == '+' || *header == '-' || *length <= 0)
		return (NULL);
	while (i - 2 > 0 && (*header >= '0' && *header <= '9'))
	{
		header++;
		i--;
	}
	if (ft_strlen(header) != 3)
		return (NULL);
	return (header);
}

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
	if (str != NULL )
		free(str);
	return (res);
}

char	**read_file(const char *file)
{
	char	*content;
	char	curr;
	char	**lines;
	int		fd;

	content = NULL;
	lines = NULL;
	curr = ' ';
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
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

	if (lines == NULL)
		return ;
	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		lines[i] = NULL;
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
