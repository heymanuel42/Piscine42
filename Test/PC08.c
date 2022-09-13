/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PC08.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:35:04 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/13 15:44:30 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

#include <stdio.h>
#include <stdlib.h>

struct	s_stock_str		*ft_str_to_tab(int ac, char **av);
void					ft_show_tab(t_stock_str *par);

int	main(int argc, char **argv)
{
	struct s_stock_str	*tab;

	tab = ft_str_to_tab(argc, argv);
	tab[2].copy[0] = 'x';
	ft_show_tab(tab);
	for(int i = 0; i < argc+1; i++)
	{
		free(tab[i].str);
		free(tab[i].copy);
	}
	free(tab);
}
