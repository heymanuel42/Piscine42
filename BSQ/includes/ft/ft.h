/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:52:40 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/20 21:17:36 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_sqrt(int nb);
int		ft_pow(int nb, int power);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	**ft_split(char *str, char *charset);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_str_is_numeric(char *str);

#endif
