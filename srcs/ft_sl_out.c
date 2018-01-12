/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 19:35:11 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 19:35:14 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <termcap.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

void	ft_sl_getsize(int sig)
{
	struct winsize	wsize;

	ioctl(0, TIOCGSIZE, &wsize);
	ft_sl_singleton()->col = wsize.ws_col;
	ft_sl_singleton()->line = wsize.ws_row;
	if (sig == SIGWINCH)
	{
		tputs(tgetstr("cl", NULL), 1, &ft_sl_putchar);
		ft_sl_put();
	}
}

void	ft_sl_put(void)
{
	t_dlst	*list;
	t_glob	*glob;
	char	*cm;
	int		x;
	int		y;

	x = 0;
	y = 0;
	glob = ft_sl_singleton();
	cm = tgetstr("cm", NULL);
	list = (glob->lst)->next;
	if (ft_sl_sizecheck(list, glob))
		return ;
	while (list)
	{
		tputs(tgoto(cm, x, y), 1, &ft_sl_putchar);
		ft_sl_putone(list);
		if (++y > glob->line - 1 && (y = 0) == 0)
			x += glob->maxlen + 2;
		else
			ft_putchar_fd('\n', 0);
		list = list->next;
	}
}

int		ft_sl_sizecheck(t_dlst *lst, t_glob *g)
{
	if (((ft_sl_countlst(lst) / g->line) + 1) * (g->maxlen + 2) > g->col)
	{
		ft_sl_errorsize();
		return (1);
	}
	return (0);
}

void	ft_sl_putone(t_dlst *list)
{
	if (list->cond == 1)
		ft_sl_printcolor(list, UNDERLINE);
	if (list->cond == 2)
		ft_sl_printcolor(list, REV);
	if (list->cond == 3)
		ft_sl_printcolor(list, REVUNDER);
	if (list->cond == 0)
		ft_sl_printcolor(list, NORMAL);
}

void	ft_sl_printcolor(t_dlst *list, char *type)
{
	if (list->type == 'd')
		ft_putstr_col(list->name, BLUE, type, 0);
	else if (list->type == 'x')
		ft_putstr_col(list->name, RED, type, 0);
	else if (list->type == 's')
		ft_putstr_col(list->name, CYAN, type, 0);
	else if (list->type == 'p')
		ft_putstr_col(list->name, PURPLE, type, 0);
	else if (list->type == 'c')
		ft_putstr_col(list->name, GREEN, type, 0);
	else if (list->type == 'b')
		ft_putstr_col(list->name, GREEN, type, 0);
	else
		ft_putstr_col(list->name, WHITE, type, 0);
}
