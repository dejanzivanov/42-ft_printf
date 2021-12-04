/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:13:33 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:33 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(char *str, unsigned long n, int base, int c)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[i] = '0';
		i++;
	}
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
		{
			str[i] = (n % base) - 10 + c;
			i++;
		}
		else
		{
			str[i] = (n % base) + '0';
			i++;
		}
		n /= base;
	}
	str[i] = '\0';
	return (str);
}
