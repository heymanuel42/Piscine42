/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:30:14 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/04 15:23:03 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_char_is_lowercase(*str))
		{
			*str = *str - ('a' - 'A');
		}
		str++;
	}
	return (start);
}
