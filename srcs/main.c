/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:38:15 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 17:38:18 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_select.h"

int		main(int ac, char **av)
{
	char	buffer[2048];

	if (ac < 2)
		ft_sl_error(0);
	tcgetattr(0, &(ft_sl_singleton()->term));
	ft_sl_signal();
	ft_sl_singleton()->lst = ft_sl_dolst(ac, av);
	ft_sl_singleton()->maxlen = ft_sl_getmaxlen(ft_sl_singleton()->lst);
	ft_sl_getsize(0);
	if (tgetent(buffer, getenv("TERM")) < 1)
		ft_sl_error(2);
	ft_sl_initshell();
	ft_sl_read();
	return (0);
}

void	ft_sl_initshell(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, &ft_sl_putchar);
	tputs(tgetstr("vi", NULL), 1, &ft_sl_putchar);
}
