/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_dokey.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 19:37:11 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/10 19:37:15 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

void	ft_sl_key(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] == 65)
		ft_sl_moveup();
	else if (key[0] == 27 && key[1] == 91 && key[2] == 66)
		ft_sl_movedw();
	else if (key[0] == 27 && key[1] == 91 && key[2] == 67)
		ft_sl_moveright();
	else if (key[0] == 27 && key[1] == 91 && key[2] == 68)
		ft_sl_moveleft();
	else if (key[0] == 32 && key[1] == 0 && key[2] == 0)
		ft_sl_dospace();
	else if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		ft_sl_doentry();
	else if (key[0] == 127 && key[1] == 0 && key[2] == 0)
		ft_sl_del();
	else if (key[0] == 126 && key[1] == 0 && key[2] == 0)
		ft_sl_del();
	else if (key[0] >= 97 && key[0] <= 122 && key[1] == 0 && key[2] == 0)
		ft_sl_search(key[0]);
}

void	ft_sl_exit(void)
{
	tputs(tgetstr("ve", NULL), 1, &ft_sl_putchar);
	tputs(tgetstr("cl", NULL), 1, &ft_sl_putchar);
	tputs(tgetstr("te", NULL), 1, &ft_sl_putchar);
	tcsetattr(0, 0, &(ft_sl_singleton()->term));
}

void	ft_sl_del(void)
{
	t_dlst	*list;
	t_dlst	*tmp;

	list = ft_sl_singleton()->lst;
	tmp = list->next;
	while (tmp->cond % 2 == 0)
		tmp = tmp->next;
	if (tmp->next)
		(tmp->next)->cond += 1;
	else
		(tmp->prev)->cond += 1;
	if ((int)ft_strlen(tmp->name) == ft_sl_singleton()->maxlen)
	{
		ft_sl_delone(&list, tmp);
		ft_sl_singleton()->maxlen = ft_sl_getmaxlen(list);
	}
	else
		ft_sl_delone(&list, tmp);
	if (list->next == NULL)
	{
		ft_sl_exit();
		exit(0);
	}
}

void	ft_sl_dospace(void)
{
	t_dlst	*list;
	t_dlst	*tmp;

	list = ft_sl_singleton()->lst;
	tmp = list->next;
	while (tmp->cond % 2 == 0)
		tmp = tmp->next;
	if (tmp->next == NULL)
	{
		if (tmp->cond == 3)
			tmp->cond = 0;
		else
			tmp->cond = 2;
		(list->next)->cond += 1;
	}
	else
	{
		if (tmp->cond == 3)
			tmp->cond = 0;
		else
			tmp->cond = 2;
		(tmp->next)->cond += 1;
	}
}

void	ft_sl_doentry(void)
{
	t_dlst	*list;
	int		nb;

	ft_sl_exit();
	nb = 0;
	list = ft_sl_singleton()->lst->next;
	while (list)
	{
		if (list->cond >= 2)
			nb++;
		list = list->next;
	}
	list = ft_sl_singleton()->lst->next;
	while (list)
	{
		if (list->cond >= 2)
		{
			ft_putstr(list->name);
			if (nb-- > 1)
				ft_putstr(" ");
		}
		list = list->next;
	}
	ft_putendl("");
	exit(0);
}
