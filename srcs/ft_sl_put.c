/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:25:34 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 18:25:37 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include "libft.h"
#include "ft_select.h"

int		ft_sl_putchar(int c)
{
	write(0, &c, 1);
	return (1);
}

int		ft_sl_putstr(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(0, str, len);
	return (len);
}

void	ft_sl_read(void)
{
	char	key[4];

	ft_bzero(key, 4);
	while (!(key[0] == 27 && key[1] == 0 && key[2] == 0))
	{
		ft_bzero(key, 3);
		tputs(tgetstr("cl", NULL), 1, &ft_sl_putchar);
		ft_sl_put();
		read(0, key, 3);
		ft_sl_key(key);
	}
	ft_sl_exit();
}
