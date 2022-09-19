/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:33:36 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:47:19 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"
#include "includes/ft/ft.h"

int	main(void)
{
	t_map	*map;

	map = read_map("maps/50x80_1");
	draw_map(map);

	ft_putstr("\n");
	ft_putstr("empty : ");
	ft_putchar(map->empty);
	ft_putstr("\n");
	ft_putstr("filled : ");
	ft_putchar(map->fill);
	ft_putstr("\n");
	ft_putstr("obstacle : ");
	ft_putchar(map->obstacle);
	ft_putstr("\n");
	free_map(map);
	return (0);
}
