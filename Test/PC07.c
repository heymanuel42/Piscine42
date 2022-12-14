/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PC07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:51:29 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/15 19:49:58 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(char *s1);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **s2, char *sep);
char	**ft_split(char *str, char *charset);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{
	char	*s1 = "Hello world";
	char	*cpy = ft_strdup(s1);


	printf("%s\n", s1);
	cpy[3] = 'X';
	printf("%s\n", cpy);
	free(cpy);

	int	*range = ft_range(-40,20);
	for(int i = 0; i < 60; i++)
	{
		printf("%d ,", range[i]);
	}

	printf("\n");
	free(range);

	char *test[10];
	for(int i = 0; i < 10; i++)
	{
		test[i] = "Hello dofghasdghadioghadio nfasoifjasdofhasopfhjasdiofhaooisdfh";
	}
	(void) argc;
	(void) argv;
	char	*res;
	res = ft_strjoin(10, test, "##^\n");

	printf("%s\n",res);
	free(res);


	char *res2;
	res2 = ft_convert_base("4","0123456789","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;
	res2 = ft_convert_base("123","01234","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;
	res2 = ft_convert_base("A","0123456789ABCDEF","0123456789");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;
	res2 = ft_convert_base("FFF","0123456789ABCDEF","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;
	res2 = ft_convert_base("-0","0123456789","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;
	res2 = ft_convert_base("-100","01234567","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;







	return 0;
}
