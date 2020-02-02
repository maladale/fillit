/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:00:22 by cmela             #+#    #+#             */
/*   Updated: 2020/01/07 18:00:24 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fill.h"

static char	g_letter;
static int	*g_iter;

void	clear_field(char *field, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		if (field[i] == g_letter)
			field[i] = '.';
		i++;
	}
}

int		try_place(int size, int pos, int *tetr, char *board)
{
	int x;
	int y;
	int i;

	i = -1;
	while (i < 3)
	{
		x = pos % size + ((tetr[i + 1] - 1) % 4 - (tetr[0] - 1) % 4);
		y = pos / size + ((tetr[i + 1] - 1) / 4 - (tetr[0] - 1) / 4);
		if (x >= size || y >= size || x < 0 || y < 0)
		{
			clear_field(board, size);
			return (0);
		}
		if (board[x + y * size] != '.')
		{
			clear_field(board, size);
			return (0);
		}
		board[x + y * size] = g_letter;
		i++;
	}
	return (1);
}

int		try_tetr(int size, int *tetr, char *board, int iter)
{
	int pos;
	int i;

	pos = 0;
	i = 0;
	while (pos < size * size)
	{
		if (try_place(size, pos, tetr, board))
		{
			i++;
			if (i == iter)
				return (1);
			clear_field(board, size);
		}
		pos++;
	}
	return (0);
}

int		find_size(int n, int *tetr, int size, char *board)
{
	int i;

	i = 0;
	while (i < n)
	{
		g_iter[i] = 1;
		i++;
	}
	g_letter = 'A';
	while (g_letter < 'A' + n)
	{
		if (try_tetr(size, &(tetr[(int)(g_letter - 'A') * 4]),
					board, g_iter[(int)(g_letter - 'A')]))
			g_letter++;
		else
		{
			if (g_letter-- <= 'A')
				return (1);
			g_iter[(int)(g_letter - 'A')]++;
			g_iter[(int)(g_letter - 'A') + 1] = 1;
			clear_field(board, size);
		}
	}
	return (0);
}

void	fillit(int n, int *tetr)
{
	int		size;
	char	*board;

	size = ft_sqrt(n * 4);
	board = (char *)malloc(size * size);
	g_iter = (int *)malloc(sizeof(int) * n);
	ft_memset((void *)board, (int)'.', size * size);
	while (find_size(n, tetr, size, board))
	{
		size++;
		free(board);
		board = (char *)malloc(size * size);
		ft_memset(board, (int)'.', size * size);
	}
	print(board, size);
	free(board);
	free(g_iter);
}
