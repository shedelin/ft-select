/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:41:06 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 17:41:08 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <termcap.h>
#include "libft.h"
#include "ft_select.h"

void	ft_sl_error(int error)
{
	if (error == 0)
		ft_putendl_fd("Not enough arguments.", 2);
	if (error == 1)
		ft_putendl_fd("Malloc fail.", 2);
	if (error == 2)
		ft_putendl_fd("Incompatible terminal.", 2);
	if (error == 3)
		ft_putendl_fd("Try to del bad link.", 2);
	exit(error);
}

void	ft_sl_errorsize(void)
{
	tputs(tgetstr("cl", NULL), 1, &ft_sl_putchar);
	ft_putendl_fd("window's too small, enlarge", 2);
}
