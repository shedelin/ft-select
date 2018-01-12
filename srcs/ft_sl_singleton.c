/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_singleton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 20:08:43 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 20:08:44 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

t_glob	*ft_sl_singleton(void)
{
	static t_glob	*glob;

	if (glob == NULL)
		glob = (t_glob *)malloc(sizeof(t_glob));
	return (glob);
}
