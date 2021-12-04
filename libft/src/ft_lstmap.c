/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:20:05 by dzivanov          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:48 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Iterates the list ’lst’ and applies the function ’f’ to the content of each
**	element. Creates a new list resulting of the successive applications of
**	the function ’f’. The ’del’ function is used to delete the content of an
**	element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_list;

	if (lst == 0)
		return (NULL);
	new_list = 0;
	while (lst)
	{
		temp_list = ft_lstnew(f(lst->content));
		if (!temp_list)
		{
			ft_lstdelone(temp_list, del);
		}
		else
		{
			ft_lstadd_back(&new_list, temp_list);
		}
		lst = lst->next;
	}
	return (new_list);
}
/*
**	#1. The adress of a pointer to an element.
**	#2. The adress of the function used to iterate on
**	#3. The adress of the function used to delete the content of an element
**	if needed.
**
**	1) We are starting with the 2 list pointers and the paremeter checks.
**	If lst or f are NULL we return NULL;
**
**	2) Itteration is performed as long as we did not come to the last element
**	in the linked lists. During that itteration we create new list using
**	ft_lstnew function which creates new list and applis F function on the
**	content of that list.
**
**	3) In case that list creation has failed we delete that list using
**	ft_lstclear function and apply del function to it. and we return NULL in
**	in this case.
**
**	4) In case that everything went successfully we add the new list to the end
**	of created list with the ft_lstadd_back. And we loop through it until we
**	come to the end of the linked list.
**
**	5) In the end we just return "new_list" which contains all the newly created
**	lists that we have created.
**
*/