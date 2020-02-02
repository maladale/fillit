/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:31:08 by cmela             #+#    #+#             */
/*   Updated: 2020/02/01 12:43:42 by maladale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fill.h"

static int	g_w;

int		valid_one(char *map, int *tetr, int *n)
{
	int i;
	int x;

	if ((i = map_size(map)) < 545 && (i > 0))
	{
		while ((x = check_block(map, &(tetr[(*n) * 4]))) == 1)
			(*n)++;
		if (x == 2 && g_w > i - 20)
			return (2);
		if (x == 0)
			return (0);
	}
	return (0);
}

void	zero(int *a, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		a[i] = 0;
		i++;
	}
}

int		map_size(char *map)
{
	int i;

	i = 0;
	while (map[i] == '.' || map[i] == '#' || map[i] == '\n')
		i++;
	if (i > 0 && map[i] == '\0')
		return (i);
	if (map[i] != '.' || map[i] != '#' || map[i] != '\n' || map[i] != '\0')
		return (0);
	return (i);
}

int		check(int *a, char m, int *tetr)
{
	if (a[0] == 16 && a[1] == 4 && g_w > 21 && a[4] == 4 && check_form(tetr)
			&& (m != '.') && (m != '#'))
		return (2);
	if (a[0] == 16 && a[1] == 3 && a[4] == 4 && check_form(tetr))
		return (2);
	return (0);
}

int		check_block(char *map, int *tetr)
{
	int a[5];

	zero(a, 5);
	while ((map[g_w] == '.' || map[g_w] == '#'
				|| map[g_w] == '\n') && a[2] < 20)
	{
		if (map[g_w] == '.' || map[g_w] == '#')
			a[0]++;
		if (map[g_w] == '#')
			tetr[a[4]++] = a[0];
		if (map[g_w] == '\n')
			a[1]++;
		if (map[g_w] == '\n' && map[g_w + 1] == '\n' && map[g_w + 2] != '\n')
			a[3]++;
		g_w++;
		a[2]++;
	}
	if (a[0] == 16 && a[1] == 4 && a[3] == 1 && a[4] == 4 && check_form(tetr))
	{
		g_w++;
		return (1);
	}
	return (check(a, map[g_w], tetr));
}
