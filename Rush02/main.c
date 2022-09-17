/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:27:20 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 17:07:31 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dictionnary.h"
#include <stdlib.h>
#include <stdio.h>

void	create_directory(const char *filename)
{
	g_dictionnary = NULL;
	add(&g_dictionnary, create_pair("1", "one"));
	add(&g_dictionnary, create_pair("2", "two"));
	add(&g_dictionnary, create_pair("3", "three"));
	add(&g_dictionnary, create_pair("4", "four"));
	add(&g_dictionnary, create_pair("5", "five"));
	add(&g_dictionnary, create_pair("6", "six"));
	add(&g_dictionnary, create_pair("7", "seven"));
	add(&g_dictionnary, create_pair("8", "eight"));
	add(&g_dictionnary, create_pair("9", "nine"));
	add(&g_dictionnary, create_pair("10", "ten"));
	add(&g_dictionnary, create_pair("20", "twenty"));
	add(&g_dictionnary, create_pair("30", "thiry"));
	add(&g_dictionnary, create_pair("40", "fourty"));
	add(&g_dictionnary, create_pair("50", "fifty"));
	add(&g_dictionnary, create_pair("60", "sixty"));
	add(&g_dictionnary, create_pair("70", "seventy"));
	add(&g_dictionnary, create_pair("80", "eighty"));
	add(&g_dictionnary, create_pair("90", "ninety"));
	add(&g_dictionnary, create_pair("100", "hundred"));
	add(&g_dictionnary, create_pair("1000", "thousand"));
	add(&g_dictionnary, create_pair("1000000", "million"));
	add(&g_dictionnary, create_pair("1000000000", "billion"));
	add(&g_dictionnary, create_pair("1000000000000", "trillion"));
	add(&g_dictionnary, create_pair("1000000000000000", "quadrillion"));
	add(&g_dictionnary, create_pair("1000000000000000000", "quintillion"));
	add(&g_dictionnary, create_pair("1000000000000000000000", "sextillion"));
	add(&g_dictionnary, create_pair("1000000000000000000000000", "septillion"));
	add(&g_dictionnary, create_pair("1000000000000000000000000000", "octillion"));
	add(&g_dictionnary, create_pair("1000000000000000000000000000000", "nonillion"));
	add(&g_dictionnary, create_pair("1000000000000000000000000000000000", "decillion"));
	add(&g_dictionnary, create_pair("1000000000000000000000000000000000000", "undecillion"));
}

int	main(void)
{
	create_directory("hello.txt");
	printf("found %s\n", get_dict_value(g_dictionnary, "10"));
	printf("found %s\n", get_dict_value(g_dictionnary, "100"));
	printf("found %s\n", get_dict_value(g_dictionnary, "32"));
	free_dict(g_dictionnary);
	return (0);
}
