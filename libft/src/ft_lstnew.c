/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:23:05 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:50 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Allocates (with malloc(3)) and returns a new element. The variable ’content’
**	is initialized with the value of the parameter ’content’. The variable
**	’next’ is initialized to NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

/*
**	#1. The content to create the new element with.
**
**	1) Creating temporary list which will get allocating memory, and return,
**	fresh linked list. Which will receive the content of the parameters that
**	are being passed through the function.
**
**	2) If allocation has been performed successfully we will add the content
**	of parameters to our freshly created function, and we will set "next"
**	element to NULL. Afterwards we are going to return our new element.
**
**
**
*/