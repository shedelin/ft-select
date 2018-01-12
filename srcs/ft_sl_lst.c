/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:39:18 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 17:39:21 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

void	ft_sl_lstaddend(t_dlst **lst, t_dlst *new)
{
	t_dlst	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_dlst	*ft_sl_creatlst(char *name, int condition, char type)
{
	t_dlst	*new;

	if ((new = (t_dlst *)malloc(sizeof(t_dlst))))
	{
		new->next = NULL;
		new->prev = NULL;
		new->name = ft_strdup(name);
		new->cond = condition;
		new->type = type;
		return (new);
	}
	ft_sl_error(1);
	return (NULL);
}

void	ft_sl_delone(t_dlst **lst, t_dlst *todel)
{
	if ((*lst)->next == NULL || *lst == todel)
		ft_sl_error(3);
	(todel->prev)->next = todel->next;
	if (todel->next)
		(todel->next)->prev = todel->prev;
	ft_sl_freelst(todel);
}

void	ft_sl_freelst(t_dlst *todel)
{
	if (todel)
	{
		ft_strdel(&(todel->name));
		free(todel);
	}
}

int		ft_sl_countlst(t_dlst *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
