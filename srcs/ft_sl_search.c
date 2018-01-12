/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/29 17:25:12 by shedelin          #+#    #+#             */
/*   Updated: 2014/04/29 17:25:15 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_sl_search(char c)
{
	t_dlst	*list;
	t_dlst	*tmp;
	t_dlst	*tmp2;

	list = ft_sl_singleton()->lst;
	tmp = list->next;
	while (tmp->cond % 2 == 0)
		tmp = tmp->next;
	tmp->cond -= 1;
	tmp2 = tmp->next;
	while (tmp2 && tmp2->name[0] != c && (tmp2->name[0] + 32) != c)
		tmp2 = tmp2->next;
	if (tmp2)
		tmp2->cond += 1;
	else
	{
		tmp2 = list;
		while (tmp2 && tmp2->name[0] != c && (tmp2->name[0] + 32) != c)
			tmp2 = tmp2->next;
		if (tmp2)
			tmp2->cond += 1;
		else
			tmp->cond += 1;
	}
}
