/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:37:34 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 21:02:10 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0
		&& *s1 != '\0'
		&& *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if( n==0 )
		return 0;
	return (*s1 - *s2);
}
