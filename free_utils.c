/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:24:02 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 03:27:03 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_two(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
}

void	free_all(char **s1, char **s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return ;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	i = 0;
	while (s2[i])
	{
		free(s2[i]);
		i++;
	}
	free(s2);
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
