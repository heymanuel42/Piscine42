/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:52:39 by ejanssen          #+#    #+#             */
/*   Updated: 2022/09/10 09:38:10 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 4

int	check_row_col(int *board, int x, int y, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (x != i)
			if (board[i * SIZE + y] == 60)
				return (0);
		i++;
	}
	while (j < size)
	{
		if (y != j)
			if (board[j * SIZE + x] == 60)
				return (0);
		j++;
	}
	return (1);
}

int	check_diagonal(int *board, int x, int y, int size)
{
	int	i;
	int	j;

	if (x + y <= size)
	{
		i = 0;
		j = x + y;
	}
	else
	{
		i = size;
		j = (x + y) % size;
	}
	while (i > (x + y) % size)
	{
		if (i != x && j != y)
			if (board[i * SIZE + j] == 60)
				return (0);
		i++;
		j--;
	}
	return (1);
}

int	place(int *board, int x, int y, int current)
{
	if (!check_diagonal(board, x, y, SIZE)
		|| !check_row_col(board, x, y, SIZE))
	{
		return (0);
	}
	else if (current >= SIZE)
	{
		return (0);
	}
	else if (current < SIZE)
	{
		board[x * SIZE + y] = 60;
		place(board, x +1, y, current);
		place(board, x, y + 1, current++);
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	return (0);
}
