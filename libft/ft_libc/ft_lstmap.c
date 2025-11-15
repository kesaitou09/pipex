/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:09 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 05:53:11 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*new_elem;

	if (!lst)
		return (NULL);
	begin_list = ft_lstnew((f)(lst->content));
	if (!begin_list)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew((f)(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_list, new_elem);
		lst = lst->next;
	}
	return (begin_list);
}
