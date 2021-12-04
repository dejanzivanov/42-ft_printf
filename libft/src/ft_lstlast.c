/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:07:29 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:47 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	#1. The beginning of the list.
**	Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

/*
**	1) Check performed if passed parameter is not NULL.
**
**	2) Iteration on the list is performed by check the "next" link, while it's
**	not null we itterate through the list and search for the last list, when the
**	while loop is broken and "next" link is found to be null, we just return the
**	current list which is the last node in the linked list.
*/