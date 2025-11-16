/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:04 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int	main(void)
//{
//	char buf1[] = "";
//	char buf2[] = "jjkkk";
//	char buf3[] = "aaaaaaaaaa";

//	char dst1[10];
//	char dst2[10];
//	char dst3[10];
//	char dst4[10];
//	char dst5[10];

//	size_t i = 11;
//	size_t j = 11;
//	printf("dst1  %zu\n%s\n", ft_strlcpy(dst1, buf2, i), dst1);
//	printf("dst2  %zu\n%s\n", strlcpy(dst2, buf2, j), dst2);
//	printf("dst3  %zu\n%s\n", ft_strlcpy(dst3, buf3, sizeof(dst3)), dst3);
//	printf("dst4  %zu\n%s\n", strlcpy(dst4, buf3, sizeof(dst4)), dst4);
//}