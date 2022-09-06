/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:51:46 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/04 15:23:57 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

char	*ft_strlowcase(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_char_is_uppercase(*str))
		{
			*str = *str + ('a' - 'A');
		}
		str++;
	}
	return (start);
}
