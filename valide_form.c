/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:32:54 by cmela             #+#    #+#             */
/*   Updated: 2020/01/18 15:32:55 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

int		form_one(int a[])
{
	if (a[1] - a[0] == 1)
	{
		if (a[2] - a[1] == 1)
		{
			if ((a[3] - a[2] == 1) || (a[3] - a[2] == 2) ||
					(a[3] - a[2] == 3) || (a[3] - a[2] == 4))
				return (1);
		}
		else if (a[2] - a[1] == 2 && a[3] - a[2] == 1)
			return (1);
		else if (a[2] - a[1] == 3)
		{
			if ((a[3] - a[2] == 1) || (a[3] - a[2] == 4))
				return (1);
		}
		else if (a[2] - a[1] == 4)
		{
			if ((a[3] - a[2] == 1) || (a[3] - a[2] == 4))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

int		form_two(int a[])
{
	if ((a[2] - a[1] == 1) && (a[3] - a[2] == 1))
		return (1);
	else
		return (0);
}

int		form_three(int a[])
{
	if ((a[2] - a[1] == 1) && ((a[3] - a[2] == 1) || (a[3] - a[2] == 3)
				|| (a[3] - a[2] == 4)))
		return (1);
	else
		return (0);
}

int		form_four(int a[])
{
	if (a[2] - a[1] == 1)
	{
		if ((a[3] - a[2] == 1) || (a[3] - a[2] == 3) || (a[3] - a[2] == 4))
			return (1);
	}
	else if (a[2] - a[1] == 3)
	{
		if (a[3] - a[2] == 1)
			return (1);
	}
	else if (a[2] - a[1] == 4)
	{
		if ((a[3] - a[2] == 1) || (a[3] - a[2] == 4))
			return (1);
	}
	return (0);
}

int		check_form(int a[])
{
	if (a[1] - a[0] == 1)
	{
		return (form_one(a) ? 1 : 0);
	}
	else if (a[1] - a[0] == 2)
	{
		return (form_two(a) ? 1 : 0);
	}
	else if (a[1] - a[0] == 3)
	{
		return (form_three(a) ? 1 : 0);
	}
	else if (a[1] - a[0] == 4)
	{
		return (form_four(a) ? 1 : 0);
	}
	return (0);
}
