/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:11:39 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 13:20:36 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft/ft.h"

char	*ft_strdup(char *src)
{
	char	*cpy;

	cpy = malloc(ft_strlen(src) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	return (ft_strcpy(cpy, src));
}
