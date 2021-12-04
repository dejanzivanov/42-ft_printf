/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:28:00 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:37:35 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

int	ft_handler_zero(t_print *tab, const char *format, int index)
{
	int	i;

	i = 0;
	index++;
	tab->zero = 1;
	while (format[index] == '0')
		index++;
	if (ft_isdigit(format[index]))
	{
		i = ft_atoi(&format[index]);
		index += ft_numlen(i);
	}
	tab->width = i;
	return (index);
}

int	ft_handler_precision(t_print *tab, const char *format, int index)
{
	int	i;

	i = 0;
	index++;
	tab->point = 1;
	if (ft_isalpha(format[index]) || format[index] == '%')
		ft_precision_checker(tab);
	while (format[index] == '0' || ft_flag_checker(format[index]))
	{
		index++;
		ft_precision_checker(tab);
	}
	if (ft_isdigit(format[index]))
	{
		i = ft_atoi(&format[index]);
		index += ft_numlen(i);
	}
	tab->precision = i;
	if (format[index] == '*')
		index = ft_handler_star(tab, format, index);
	while (format[index] == '*')
		index++;
	return (index);
}

int	ft_handler_dash(t_print *tab, const char *format, int index)
{
	index++;
	if (tab->dash == 1)
	{
		while (format[index] == '-' || format[index] == '0')
			index++;
		return (index);
	}
	tab->dash = 1;
	tab->zero = 0;
	while (format[index] == '-' || format[index] == '0')
		index++;
	index = ft_handler_width(tab, format, index);
	return (index);
}

int	ft_handler_star(t_print *tab, const char *format, int index)
{
	index++;
	if (!tab->point)
	{
		tab->width = va_arg(tab->args, int);
		ft_width_checker(tab);
	}
	else
	{
		tab->precision = va_arg(tab->args, int);
		ft_precision_checker(tab);
	}
	if (format[index] == '.')
		index = ft_handler_precision(tab, format, index);
	if (format[index] == '*')
		index = ft_handler_star(tab, format, index);
	while (format[index] == '*')
		index++;
	return (index);
}

int	ft_handler_width(t_print *tab, const char *format, int index)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[index]))
	{
		i = ft_atoi(&format[index]);
		index += ft_numlen(i);
	}
	tab->width = i;
	if (format[index] == '.')
		index = ft_handler_precision(tab, format, index);
	return (index);
}

/*
**	This file contains funcions:
**	ft_handler_zero
**	ft_handler_precision
**	ft_handler_dash
**	ft_handler_star
**	ft_handler_width
**
**	Each function is handling certain format specifier that is defined in the
**	name of the function.
*/
