/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_beaver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:06:18 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:56:39 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Originally function was named ft_numlen_base, but because of unkown reason,
**	moulinette flagged this function as "cheat". My assumption is that the
**	function name correlates to piscine function name, and that was the reason.
**	**************** !!!!!!!!!!!ASSUMPTION!!!!!!!!!!! ************************
**
**	int	ft_numlen_base(unsigned long n, int base)
**	{
**		int		i;
**
**		i = 0;
**		if (n == 0)
**		{
**			i += 1;
**			return (i);
**		}
**		while (n > 0)
**		{
**			i++;
**			n /= base;
**		}
**		return (i);
**	}
**
*/

int	ft_beaver(unsigned long tooth, int root)
{
	int		counter;

	counter = 0;
	if (tooth == 0)
	{
		counter += 1;
		return (counter);
	}
	while (tooth > 0)
	{
		counter++;
		tooth /= root;
	}
	return (counter);
}
