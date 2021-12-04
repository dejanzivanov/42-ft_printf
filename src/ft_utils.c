/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:19:28 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/02 00:16:36 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

/*
**	This file is used as utility file that helps ft_printf function
**	differentiate between each flags and specifiers.
**	ft_init - is used to initiate the structure
**	ft_reset - is used to restart the values in the structure
**	ft_handle_variables - separates flags into their given format
**	ft_handle_format - handles requested format specifiers(see ft_printf)
*/

t_print	*ft_reset(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->percentage = 0;
	tab->space_flag = 0;
	return (tab);
}

t_print	*ft_init(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->total_length = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->percentage = 0;
	tab->space_flag = 0;
	return (tab);
}

int	ft_handle_variables(t_print *tab, const char *format, int index)
{
	if (format[index] == 'c')
		ft_print_char(tab);
	else if (format[index] == 's')
		ft_print_string(tab);
	else if (format[index] == 'd' || format[index] == 'i')
		ft_print_integer(tab);
	else if (format[index] == 'u')
		ft_print_unsigned_int(tab);
	else if (format[index] == 'p')
		ft_print_pointer(tab);
	else if (format[index] == 'x' || format[index] == 'X')
		ft_print_hexadecimal(tab, format[index] - 23);
	else if (format[index] == '%')
		ft_print_percentage(tab);
	return (index);
}

int	ft_handle_format(t_print *tab, const char *format, int index)
{
	while (!(ft_isalpha(format[index]) || format[index] == '%'))
	{
		if (format[index] == ' ')
			index = ft_handler_space(tab, index);
		if (format[index] == '0')
			index = ft_handler_zero(tab, format, index);
		if (format[index] == '*')
			index = ft_handler_star(tab, format, index);
		if (format[index] == '-')
			index = ft_handler_dash(tab, format, index);
		if (format[index] == '.')
			index = ft_handler_precision(tab, format, index);
		if (ft_isdigit(format[index]))
		{
			index = ft_handler_width(tab, format, index);
		}
	}
	ft_handle_variables(tab, format, index);
	ft_reset(tab);
	return (index);
}
