/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:10:00 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:37:51 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

void	ft_print_point(t_print *tab)
{
	ft_update_tab_string(NULL, tab, 0);
	while (tab->width--)
		tab->total_length += write(1, " ", 1);
}

void	ft_print_string(t_print *tab)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	s = va_arg(tab->args, char *);
	if (!s)
		s = "(null)";
	if (s && tab->point == 1 && tab->precision == 0)
		return (ft_print_point(tab));
	len = ft_update_tab_string(s, tab, len);
	if (!tab->dash && tab->width > len)
		ft_right_character_handler(tab, len);
	if (tab->precision > 0)
		while (s[i] && tab->precision--)
			tab->total_length += write(1, &s[i++], 1);
	else
		while (s[i])
			tab->total_length += write(1, &s[i++], 1);
	if (s && tab->dash && tab->width)
		ft_left_character_handler(tab, len);
}

/*
**	In this file we have 2 functions:
**	ft_print_string - we use this function to print string and handle paddings
**	ft_print_point - handles edge cases where empty spaces or null chars need
**	to be handled
*/
