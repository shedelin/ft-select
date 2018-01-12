/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 18:09:14 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/11 19:07:50 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termcap.h>
#include "ft_select.h"

void	ft_sl_moveup(void)
{
	t_dlst	*list;
	t_dlst	*tmp;

	list = ft_sl_singleton()->lst;
	tmp = list->next;
	while (tmp->cond % 2 == 0)
		tmp = tmp->next;
	tmp->cond -= 1;
	if (tmp->prev == list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->cond += 1;
	}
	else
		(tmp->prev)->cond += 1;
}

void	ft_sl_movedw(void)
{
	t_dlst	*list;
	t_dlst	*tmp;

	list = ft_sl_singleton()->lst;
	tmp = list->next;
	while (tmp->cond % 2 == 0)
		tmp = tmp->next;
	if (tmp->next == NULL)
		list->next->cond += 1;
	else
		(tmp->next)->cond += 1;
	tmp->cond -= 1;
}

void	ft_sl_moveright(void)
{
	t_dlst	*list;
	t_dlst	*tmp;
	int		i;
	int		len;

	list = ft_sl_singleton()->lst->next;
	len = ft_sl_singleton()->line;
	tmp = list;
	while (tmp->cond % 2 == 0)
		tmp = tmp->next;
	tmp->cond -= 1;
	i = 0;
	while (tmp->next && i < len)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->cond += 1;
}

void	ft_sl_moveleft(void)
{
	t_dlst	*list;
	t_dlst	*tmp;
	int		i;
	int		len;

	i = 0;
	list = ft_sl_singleton()->lst->next;
	tmp = list;
	len = ft_sl_singleton()->line;
	while (tmp->cond % 2 == 0)
	{
		i++;
		tmp = tmp->next;
	}
	tmp->cond -= 1;
	if (i - len < 0)
		while ((tmp->prev)->prev)
			tmp = tmp->prev;
	else
		while (len--)
			tmp = tmp->prev;
	tmp->cond += 1;
}
