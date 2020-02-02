/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:00:32 by cmela             #+#    #+#             */
/*   Updated: 2020/01/19 18:42:33 by maladale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H

# include <string.h>
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		check_block(char *map, int *tetr);
int		map_size(char *map);
int		valid_one(char *map, int *tetr, int *n);
int		check_form(int *a);
int		ft_sqrt(int n);
void	print(char *board, int size);
void	fillit(int n, int *tetr);
int		validate(int fd, int *n, int *tetr);
#endif
