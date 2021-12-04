/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:20:21 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:18 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	This is recreation of the atoi function in C. We take string of characters
**	that are supposed to be a number converted into an int. According to the man
**	"The atoi function converts the initial portion of the string point to
**	by str to int representation."
**
*/

#include "libft.h"

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	check_overflow(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign(str[i++]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n >= 9223372036854775807)
		{
			n = check_overflow(sign);
			break ;
		}
		n = n * 10 + (str[i++] - '0');
	}
	return (sign * (int)n);
}

/*
**	1) First part of the function starts with the three variables that will
**	hold our value to be returned even if they are long, result in the end
**	is casted to int so we can cover all aspects of integer range.
**
**	2) Once we are done checking for white spacing, we are checking for - or +
**	signs so we know what we need to multiply our result with accordingly.
**
**	3) For the first character resultat is always set currently at 0. We
**	multiply it by 1- to get the digitcal placement where it should be.
**	Afterwards we do the ascii conversion to its numberical value, we then start
**	our loop again, and continue until we hit a character that is not a number.
**
**	In the end we return score value that is muplitplied by the negative result,
**	which can be positive or negative. And the last but not least, we have
**	integer cast type so the equation can be converted to in and be returned as.
**
**
**
**
**

*/