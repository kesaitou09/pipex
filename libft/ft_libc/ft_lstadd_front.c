/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:56:56 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:11:06 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
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

// 	ft_lstadd_front(&list1, list2);
// 	printf("%d\n",*(int *)list1 ->content);
// 	printf("%d\n",*(int *)list2 ->next ->content);
// }