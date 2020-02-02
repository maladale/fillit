/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:51:51 by cmela             #+#    #+#             */
/*   Updated: 2020/02/01 12:56:36 by maladale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		n;
	int		*tetr;
	int		fd;
	char	buf;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	n = 0;
	tetr = (int *)malloc(sizeof(int) * 26 * 4);
	if (read(fd, &buf, 0) == -1 || validate(fd, &n, tetr) == 0)
	{
		ft_putstr("error\n");
		free(tetr);
		exit(-1);
	}
	fillit(n, tetr);
	free(tetr);
	return (0);
}
