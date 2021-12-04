/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:28:04 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:39:25 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Allocates (with malloc(3)) and returns a new string, which is the result
**	of the concatenation of ’s1’ and ’s2’.
**
**
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*
**	1) This function work in the way that joins two strings together.
**	in the initial part of the function we get the length of the both strings,
**	an then allocate the memory to it incluing the place for NULL terminating
**	character. If the memory allocation faile, we return empty pointer.
**
**	2) In the second part of the function we give all the character from first
**	and second pointer to a temporary pointer, and in the end, we put the NULL
**	terminating character to it and return it.
**
*/