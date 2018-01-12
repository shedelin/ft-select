/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_dolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:05:28 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 18:05:30 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include "libft.h"
#include "ft_select.h"

t_dlst				*ft_sl_dolst(int ac, char **av)
{
	t_dlst			*lst;
	int				i;

	i = 1;
	lst = ft_sl_creatlst("", -1, 'z');
	while (i < ac)
	{
		ft_sl_lstaddend(&lst, ft_sl_creatlst(av[i], 0, ft_sl_gettype(av[i])));
		i++;
	}
	(lst->next)->cond = 1;
	return (lst);
}

int					ft_sl_getmaxlen(t_dlst *lst)
{
	int				maxlen;

	maxlen = 0;
	while (lst->next)
	{
		if ((int)ft_strlen(lst->name) > maxlen)
			maxlen = ft_strlen(lst->name);
		lst = lst->next;
	}
	return (maxlen);
}

char				ft_sl_gettype(char *str)
{
	char			c;
	struct stat		data;

	stat(str, &data);
	c = '-';
	if (S_ISDIR(data.st_mode))
		c = 'd';
	else if (access(str, X_OK) == 0)
		c = 'x';
	else if (S_ISSOCK(data.st_mode))
		c = 's';
	else if (S_ISFIFO(data.st_mode))
		c = 'p';
	else if (S_ISCHR(data.st_mode))
		c = 'c';
	else if (S_ISBLK(data.st_mode))
		c = 'b';
	else if (S_ISREG(data.st_mode))
		c = '-';
	return (c);
}
