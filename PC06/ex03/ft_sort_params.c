/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:30:41 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/11 13:53:23 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	get_unsorted_smallest(char **tab, int *sid, int offset, int size)
{
	int		i;
	char	*smallest;

	smallest = "~";
	i = offset;
	while (i < size)
	{
		if (ft_strcmp(tab[i], smallest) < 0)
		{
			smallest = tab[i];
			*sid = i;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	sid;

	i = 0;
	sid = 0;
	while (i < argc)
	{
		get_unsorted_smallest(argv, &sid, i, argc);
		ft_swap(&argv[i], &argv[sid]);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '\0')
		{
			ft_putstr(argv[i]);
			ft_putstr("\n");
		}
		i++;
	}
	return (0);
}
