/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:10:38 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/05 17:14:30 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tohex(int nbr, char* base)
{
	if (nbr > 0)
	{
		ft_tohex(nbr / 16,base);
		ft_tohex(nbr % 16,base);
	}
	else{
		write(1,&base[nbr],1);
	}
}
void	ft_putnbr_base(int nbr, char *base)
{
	
}

int main()
{
	ft_tohex(16,"0123456789ABCDEF");
	return 0;
}