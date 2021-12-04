/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_updates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:02:57 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:37:38 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

int	ft_update_tab_string(char *s, t_print *tab, int len)
{
	if (s)
		len = ft_strlen(s);
	if (tab->precision > 0 && len > tab->precision)
		len = tab->precision;
	return (len);
}

void	ft_update_tab(t_print *tab, int len)
{
	if (tab->sign)
	{
		if (tab->width)
			tab->width -= 1;
	}
	if (tab->precision > 0)
		tab->zero = 0;
	if (tab->width && tab->width >= tab->precision)
	{
		if (tab->precision > len)
			tab->precision -= len;
		else
			tab->precision = 0;
		if (!tab->is_zero)
			tab->width = tab->width - tab->precision - len;
	}
	else if (tab->precision > tab->width)
	{
		tab->width = 0;
		tab->precision -= len;
	}
}

/*
**	This file contains funcions:
**	ft_update_tab_string - function used for updating structure values when the
**	string flag is being handled
**	ft_update_tab - function is being used across the project to update the
**	values after certain changes have been initiated.
*/
