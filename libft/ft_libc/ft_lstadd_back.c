/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:56:54 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:11:03 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	t_list *list1;
// 	t_list *list2;
// 	// t_list *list3;

// 	int content1;
// 	int content2;
// 	// int content3;

// 	content1 = 2;
// 	content2 = 43;
// 	// content3 = 50;

// 	list1 = ft_lstnew(&content1);
// 	list2 = ft_lstnew(&content2);

// 	ft_lstadd_back(&list1, list2);
// 	printf("%d\n",*(int *)list1 ->content);
// 	printf("%d\n",*(int *)list1 ->next ->content);
// }
