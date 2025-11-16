/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:26 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	uc;

	i = 0;
	p = s;
	uc = c;
	while (i < n)
	{
		p[i] = uc;
		i++;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char	z[5];
// 	char	z_2[5];

// 	ft_memset(z,'aa',4);
// 	z[4] = '\0';
// 	printf("%s\n",z);
// 	memset(z_2,'z',5);
// 	z_2[4] = '\0';
// 	printf("%s\n",z_2);
// }