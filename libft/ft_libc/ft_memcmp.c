/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:19 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/16 02:10:20 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
		{
			return ((int)*p1 - (int)*p2);
		}
		p1++;
		p2++;
		i++;
	}
	return (0);
}

// int main(void)
//{
//	char str1[] = "abcd";
//	char str2[] = "ab";

//	printf("my %d\n",ft_memcmp(str1,str2,30));
//	printf("libc %d\n",memcmp(str1,str2,30));
//}