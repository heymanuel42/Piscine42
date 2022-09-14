/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PC07.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:51:29 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/14 15:54:44 by ejanssen         ###   ########.fr       */
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

	char *test[30];
	for(int i = 0; i < 30; i++)
	{
		test[i] = "salut";
	}
	(void) argc;
	(void) argv;
		char	*res;
		res = ft_strjoin(30, test, ", ");

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
	res2 = ft_convert_base("","0123456789","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;
	res2 = ft_convert_base("-10","01234567","01");
	printf("%s %p\n",res2,res2);
	free(res2);
	res2 = 0;

	char *sentence = "Hello this is a sentence with 8 words";

	char **splited_sentence;
	int split_cnt = 0;

	splited_sentence  = ft_split(sentence," ");

	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s\n",splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);
	splited_sentence = ft_split(sentence,"i");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s\n",splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);

	char *sentece2 = "there are, a lot of:separators * in this %sentence";
		splited_sentence = ft_split(sentece2,",:*%");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s %p\n",splited_sentence[split_cnt], splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);

	char *sentence3 = "Hello, , World, Salut";
	splited_sentence = ft_split(sentence3,",Sl");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s %p\n",splited_sentence[split_cnt], splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);

	split_cnt = 0;
	char *sentence4 = "T5J0 	QQPvy4clLORZ	RDjQMoyhc9Xe0GIwJ9oAOo0Af8JXz" ;
	splited_sentence = ft_split(sentence4,"5U6Fx");
	while(splited_sentence[split_cnt] != NULL)
	{
		printf("%s %p\n",splited_sentence[split_cnt], splited_sentence[split_cnt]);
		split_cnt++;
	}
	while(split_cnt-1 >= 0)
	{
		free(splited_sentence[split_cnt]);
		split_cnt--;
	}
	free(splited_sentence);





	return 0;
}
