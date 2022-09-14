/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:30:22 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 14:46:28 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*str_copy(char *s, int size)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc((size + 1) * sizeof(char));
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*tab;

	tab = malloc((ac + 1) * sizeof (struct s_stock_str));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = str_copy(av[i], ft_strlen(av[i]));
		tab[i].copy = str_copy(av[i], ft_strlen(av[i]));
		i++;
	}
	tab[i].size = 0;
	tab[i].str = NULL;
	tab[i].copy = NULL;
	return (tab);
}

/*int	main(int argc, char **argv)
{
	struct s_stock_str	*tab;

	tab = ft_str_to_tab(argc, argv);
	tab[2].copy[0] = 'x';
	for(int i = 0; i < argc+1; i++)
	{
		printf("%d %s %s\n",tab[i].size,tab[i].str, tab[i].copy);
	}

	for(int i = 0; i < argc+1; i++)
	{
		free(tab[i].str);
		free(tab[i].copy);
	}
	free(tab);
	return (0);
}
*/
