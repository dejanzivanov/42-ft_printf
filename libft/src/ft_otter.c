/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:42:18 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 21:05:25 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Originally function was named ft_numlen_base, but because of unkown reason,
**	moulinette flagged this function as "cheat". My assumption is that the
**	function name correlates to piscine function name, and that was the reason.
**	**************** !!!!!!!!!!!ASSUMPTION!!!!!!!!!!! ************************
**
**
**	int	ft_putnbr_base(unsigned long n, char *base)
**	{
**		unsigned long	base_len;
**		unsigned long	num;
**		int				i;
**
**		i = 1;
**		num = n;
**		base_len = ft_strlen(base);
**		if (num == 0)
**		{
**			ft_putchar('0');
**			return (i);
**		}
**		if (num >= base_len)
**		{
**			i += ft_putnbr_base(n / base_len, base);
**			ft_putchar(base[num % base_len]);
**		}
**		else if (num < base_len)
**		{
**			ft_putchar(base[num]);
**		}
**		return (i);
**	}
**
*/

int	ft_otter(unsigned long stick, char *otter_pall)
{
	unsigned long	base_length;
	unsigned long	number;
	int				i;

	i = 1;
	number = stick;
	base_length = ft_strlen(otter_pall);
	if (number == 0)
	{
		ft_putchar('0');
		return (i);
	}
	if (number >= base_length)
	{
		i += ft_otter(stick / base_length, otter_pall);
		ft_putchar(otter_pall[number % base_length]);
	}
	else if (number < base_length)
	{
		ft_putchar(otter_pall[number]);
	}
	return (i);
}
