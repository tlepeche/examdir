/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 16:17:49 by tlepeche          #+#    #+#             */
/*   Updated: 2015/04/23 16:25:25 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *tmp;
	int tmp_2;
	int ok;

	ok = 1;
	while(ok == 1)
	{
		ok = 0;
		tmp = lst;
		while (tmp->next != NULL)
		{
			if (cmp(tmp->data, tmp->next->data) == 0)
			{
				ok = 1;
				tmp_2 = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = tmp_2;
			}
			tmp = tmp->next;
		}
	}
	return lst;
}
