/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:32:44 by cmela             #+#    #+#             */
/*   Updated: 2020/01/19 18:41:32 by maladale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include <unistd.h>

void	print(char *board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &board[i * size], size);
		i++;
		write(1, "\n", 1);
	}
}

int		ft_sqrt(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}
