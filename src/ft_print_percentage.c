/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:56:01 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 22:46:03 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/inc/libft.h"

void	ft_print_percentage(t_print *tab)
{
	if (tab->percentage)
		tab->zero = 1;
	while (tab->zero && !tab->dash && --tab->width > 0)
		tab->total_length += write(1, "0", 1);
	while (!tab->dash && --tab->width > 0)
		tab->total_length += write(1, " ", 1);
	tab->total_length += write(1, "%", 1);
	while (--tab->width > 0)
		tab->total_length += write(1, " ", 1);
}

/*
**	In this file we have only one function:
**	ft_print_percentage - its main and only purpose is to print '%' sign.
*/
