/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:27:20 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/17 19:02:28 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dictionnary.h"
#include <stdlib.h>
#include <stdio.h>

void	create_directory(t_dict **dict, const char *filename)
{
	(void) filename;
	*dict = NULL;
	add(dict, create_pair("1", "one"));
	add(dict, create_pair("2", "two"));
	add(dict, create_pair("3", "three"));
	add(dict, create_pair("4", "four"));
	add(dict, create_pair("5", "five"));
	add(dict, create_pair("6", "six"));
	add(dict, create_pair("7", "seven"));
	add(dict, create_pair("8", "eight"));
	add(dict, create_pair("9", "nine"));
	add(dict, create_pair("10", "ten"));
	add(dict, create_pair("20", "twenty"));
	add(dict, create_pair("30", "thiry"));
	add(dict, create_pair("40", "fourty"));
	add(dict, create_pair("50", "fifty"));
	add(dict, create_pair("60", "sixty"));
	add(dict, create_pair("70", "seventy"));
	add(dict, create_pair("80", "eighty"));
	add(dict, create_pair("90", "ninety"));
	add(dict, create_pair("100", "hundred"));
	add(dict, create_pair("1000", "thousand"));
	add(dict, create_pair("1000000", "million"));
	add(dict, create_pair("1000000000", "billion"));
	add(dict, create_pair("1000000000000", "trillion"));
	add(dict, create_pair("1000000000000000", "quadrillion"));
	add(dict, create_pair("1000000000000000000", "quintillion"));
	add(dict, create_pair("1000000000000000000000", "sextillion"));
	add(dict, create_pair("1000000000000000000000000", "septillion"));
	add(dict, create_pair("1000000000000000000000000000", "octillion"));
	add(dict, create_pair("1000000000000000000000000000000", "nonillion"));
	add(dict, create_pair("1000000000000000000000000000000000", "decillion"));
	add(dict, create_pair("1000000000000000000000000000000000000", "undecillion"));
}

int	main(void)
{
	t_dict	*dict;

	create_directory(&dict, "hello.txt");
	printf("found %s\n", get_dict_element_value(dict, "10"));
	printf("found %s\n", get_dict_element_value(dict, "100"));
	printf("found %s\n", get_dict_element_value(dict, "32"));
	free_dict(dict);
	return (0);
}
