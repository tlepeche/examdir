/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 15:55:28 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/23 16:16:00 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int start, int end)
{
	int *tab;
	int nb;
	int i;

	if (start > end)
		nb = start - end + 1;
	else
		nb = end - start + 1;
	tab = (int *)malloc(sizeof(int) * nb);
	i = 0;
	if (start > end)
	{
		while (start >= end)
		{
			tab[i] = start;
			i++;
			start --;
		}
	}
	else
	{
		while (start <= end)
		{
			tab[i] = start;
			i++;
			start++;
		}
	}
	return (tab);
}
