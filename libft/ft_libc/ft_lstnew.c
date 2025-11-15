/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:12 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 05:53:09 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list new_list1;
// 	int content1;
// 	int content2;

// 	content1 = 42;
// 	content2 = 1000;
// 	new_list1.content = &content1;
// 	new_list1.next = NULL;
// 	printf("%d\n", *(int *)(new_list1.content));

// 	t_list *test_list1;

// 	test_list1 = ft_lstnew(&content2);
// 	printf("%d\n", *(int *)test_list1->content);
// }