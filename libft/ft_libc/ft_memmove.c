/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:23 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	if (p1 < p2)
	{
		while (i < n)
		{
			p1[i] = p2[i];
			i++;
		}
	}
	else
	{
		while (0 < n--)
			p1[n] = p2[n];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[] = "abcdefg";
// 	char	str2[] = "abcdefg";

// 	memmove(str2 + 1, str2, (int)ft_strlen(str2));
// 	// ft_memmove(str1 + 1,str1,(ft_strlen(str1) + 3));
// 	printf("my-memmove\n%s\n", str1);
// 	printf("memmove\n%s\n", str2);
// }
