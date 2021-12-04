/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:56:08 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:37:53 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

void	ft_print_unsigned_int(t_print *tab)
{
	int				i;
	unsigned int	j;
	char			*num;
	int				len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		ft_print_zero(tab);
		return ;
	}
	num = ft_uitoa(j);
	if (!num)
		return ;
	len = ft_numlen(j);
	ft_update_tab(tab, len);
	ft_right_duplicatex(tab);
	while (num[i])
		tab->total_length += write(1, &num[i++], 1);
	ft_left_duplicatex(tab);
	free(num);
}

/*
**	ft_print_unsigned_int - ise used for printing an unsigned integer
**
**	After variable initialization we are getting the current argument using
**	variadic function. If given variable is 0 we print zero.
**
**	If not, we are continuing with function and afterwards we are turning our
**	value into ascii value using ft_uitoa(unsgined integer to ascii).
**
**	Counting the length of the number, updating the current structure,
**	printing padding on the left, printing given number, and printing padding on
**	the right in the end.
**
**	In the end we free the current character pointer(num) so there are
**	no memory leaks
*/
