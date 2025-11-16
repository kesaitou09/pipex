/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:01 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_strnlen(const char *s, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strnlen(dst, size);
	if (size <= dst_len)
		return (size + src_len);
	j = 0;
	i = dst_len;
	while (src[j] && j < size - dst_len - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (s[len] && len < n)
		len++;
	return (len);
}

// #include <bsd/string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	buf1[] = "aaa";
// 	// char	buf2[] = "jjkkkk";
// 	// char	buf3[] = "aaaaaaaaaa";

// 	char	dst1[] = "dst1dayo";
// 	// char	dst2[] = "dst2dayo";
// 	// char	dst3[10];
// 	// char	dst4[10];
// 	// char	dst5[10];

// 	printf("%zu,%s\n",strlcat(NULL,dst1,0),dst1);
// 	printf("%zu,%s\n",ft_strlcat(NULL,dst1,0),dst1);

// }
