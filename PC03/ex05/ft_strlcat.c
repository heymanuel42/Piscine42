/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:17:37 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 21:57:00 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:31:19 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 12:42:06 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_5(char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_strlcat(char *dest, char *src, unsigned int nb)
{
	int	src_id;
	int	dest_final_len;

	dest_final_len = ft_strlen_5(dest) + ft_strlen_5(src);
	src_id = 0;
	while (nb > 0 && src[src_id] != '\0')
	{
		dest[ft_strlen_5(dest) + src_id] = src[src_id];
		src_id++;
		nb--;
	}
	return (dest_final_len);
}
