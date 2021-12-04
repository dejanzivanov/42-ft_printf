/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:56:16 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 22:47:08 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

/*
**	The prototype of ft_printf should be int ft_printf(const char *, ...);
**	• You have to recode the libc’s printf function
**	• It must not do the buffer management like the real printf
**	• It will manage the following conversions: cspdiuxX%
**	• It will manage any combination of the following flags: ’-0.*’ and
**	minimum field width with all conversions.
**	• It will be compared with the real printf
**	• You must use the command ar to create your librairy, using the command
**	libtool is forbidden.
**	Flags to capture, c,s,p,d,i,u,x,X,%
**
**	udcsupxX%
**	%c - Character
**	%s - String
**	%p - Pointer Address
**	%d - Signed Decimal Integer
**	%i - Signed Decimal Integer(same as %d)
**	%u - Unsigned Decimal Integer
**	%x - Unsigned hexadecimal integer(lowercase Hex)
**	%X - Unsigned hexadecimal integer(uppercase Hex)
**	%% - Print percentage sign after double %%
**
**	%[flag][min width][precision][length modifier][conversion specifier]
**
**	Conversion Specifier
**	The conversion specifier is the part of the format specifier that determines
**	the basic formatting of the value that is to be printed.
**
**	Length Modifier
**	The length modifier is perhaps oddly-named; it does not modify the length
**	of the output. Instead, it's what you use to specify the length of the input
**
**	Precision
**	The "precision" modifier is written ".number", and has slightly different
**	meanings for the different conversion specifiers (like d or g).
**
**	Width
**	The width field is almost the opposite of the precision field. Precision
**	controls the max number of characters to print, width controls the minimum
**	number, and has the same format as precision, except without a decimal
**	point:
**
**	Flag
**	Using 0 will force the number to be padded with 0s. This only really
**	matters if you use the width setting to ask for a minimal width for your
**	number.
**
**	The Zero Flag: 0
**	The Minus Sign Flag: -
**	Finally, the minus sign will cause the output to be left-justified.
**	This is important if you are using the width specifier and you want
**	the padding to appear at the end of the output instead of the beginning:
**
**	Source: https://www.cprogramming.com/tutorial/printf-format-strings.html
**	Source:
**	https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
**	https://linux.die.net/man/3/va_start
**	c = va_arg(args, int)
**	s = va_arg(args, char *)
**	d = va_arg(args, int)
**	i = va_arg(args, int)
**	u = va_arg(args, unsigned int)
**	p = va_arg(args, unsigned long)# or #(unsigned long)va_arg(args, void *);
**	x = va_arg(args, unsigned int)
**	X = va_arg(args, unsigned int)
*/

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		r;

	if (!format)
		return (-1);
	r = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init(tab);
	i = -1;
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			i = ft_handle_format(tab, format, i + 1);
		else if (format[i] != '%')
			r += write(1, &format[i], 1);
	}
	r += tab->total_length;
	va_end(tab->args);
	free(tab);
	return (r);
}

/*
** main function : printf will return the total len of chars displayed by printf
*/
