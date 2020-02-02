/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:33:25 by cmela             #+#    #+#             */
/*   Updated: 2019/09/19 09:10:33 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

void	*ft_memset(void *mem, int c, size_t len)
{
	size_t i;

	if (len + 1 == 0)
		return (NULL);
	if (len + 1 == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((char*)mem)[i] = (unsigned char)c;
		i++;
	}
	return (mem);
}
