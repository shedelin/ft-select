/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 20:28:26 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 20:28:29 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include <libft.h>
#include "ft_select.h"

void	ft_sl_signal(void)
{
	signal(SIGINT, ft_sl_sigint);
	signal(SIGQUIT, ft_sl_sigint);
	signal(SIGWINCH, ft_sl_getsize);
	signal(SIGTSTP, ft_sl_sigtstp);
	signal(SIGCONT, ft_sl_sigcont);
}

void	ft_sl_sigint(int sig)
{
	char	key[2];

	(void)sig;
	key[0] = 3;
	key[1] = 0;
	ft_sl_exit();
	signal(SIGINT, SIG_DFL);
	ioctl(0, TIOCSTI, key);
}

void	ft_sl_sigtstp(int sig)
{
	char	key[2];

	(void)sig;
	key[0] = 26;
	key[1] = 0;
	ft_sl_exit();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, key);
}

void	ft_sl_sigcont(int sig)
{
	(void)sig;
	ft_sl_initshell();
	ft_sl_put();
}
