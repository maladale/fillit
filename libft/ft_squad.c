/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:40:22 by cmela             #+#    #+#             */
/*   Updated: 2019/09/25 19:43:57 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_squad(int n)
{
	int result;

	if (!n || n < 0)
		return (0);
	result = 0;
	while ((result * result) < n && result < 46)
		result++;
	return (result);
}