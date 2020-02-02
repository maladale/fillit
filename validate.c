/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:14:38 by cmela             #+#    #+#             */
/*   Updated: 2020/02/01 10:55:41 by maladale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int		clear_wsp(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i] != '\0')
		i++;
	i--;
	if (map[i] == '\n' && map[i - 1] != '\n')
		map[i] = '\0';
	return (1);
}

int		validate(int fd, int *n, int *tetr)
{
	char	buf[2];
	char	*map;
	char	*newmap;
	int		x;

	map = NULL;
	newmap = NULL;
	while (read(fd, buf, 1) > 0)
	{
		buf[1] = '\0';
		newmap = ft_strjoin(map, buf);
		free(map);
		map = newmap;
	}
	if (!clear_wsp(map))
		return (0);
	x = (valid_one(map, tetr, n));
	if (x == 2)
		(*n)++;
	free(map);
	if (x == 0)
		return (0);
	return (1);
}
