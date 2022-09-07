/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:56:43 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 10:16:52 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ALPHA_LOW 11
#define ALPHA_UP 22
#define SPACE 33
#define NUMERIC 44

int	ft_check_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (ALPHA_LOW);
	else if (c >= 'A' && c <= 'Z')
		return (ALPHA_UP);
	else if (c >= '0' && c <= '9')
		return (NUMERIC);
	else if (c == ' ')
		return (SPACE);
	else
		return (0);
}

char	ft_char_is_alpha(char c)
{
	if (ft_check_char(c) == ALPHA_LOW || ft_check_char(c) == ALPHA_UP)
		return (1);
	else
		return (0);
}

char	ft_char_is_alphanum(char c)
{
	if (ft_char_is_alpha(c) || ft_check_char(c) == NUMERIC)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		if (ft_check_char(*str) == ALPHA_UP)
			*str = *str + ('a' - 'A');
		str++;
	}
	str = start;
	while (*str)
	{
		if (((ft_check_char(*(str - 1)) == SPACE)
				|| (!ft_char_is_alphanum(*(str - 1))))
			&& ft_char_is_alpha(*str))
		{
			*str = *str - ('a' - 'A');
		}
		str++;
	}
	return (start);
}
