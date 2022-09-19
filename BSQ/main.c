/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:33:36 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 01:23:23 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/map.h"
#include "includes/ft/ft.h"

int	main(void)
{
	t_map	*map;

	map = read_map("maps/50x80_1");
	draw_map(map);
	free_map(map);
	return (0);
}
