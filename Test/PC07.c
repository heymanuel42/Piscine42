/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PC07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:51:29 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/12 15:53:45 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *s1);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size , char **s2,char *sep);
int	main(void)
{
	char	*s1 = "Hello world";
	char	*cpy = ft_strdup(s1);
	printf("%s\n",cpy);
	free(cpy);

	int *range = ft_range(40,100);
	for(int i = 0; i < 60; i++)
	{
		printf("%d ,",range[i]);
	}
	printf("\n");
	free(range);

	printf("%d \n",ft_ultimate_range(&range,10,20));

	if(range != NULL)
	{
		for(int i = 0; i < 10; i++)
		{
			printf("%d\n",range[i]);
		}
		free(range);
	}

	char *res;
	char *tab[] = {"Hello", "World","How are you doing"};
	res = ft_strjoin(3,tab,", ");

	printf("%s",res);
	free(res);
	return 0;
}
