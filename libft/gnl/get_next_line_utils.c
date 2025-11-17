/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:14 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 12:59:22 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)(s));
		}
		s++;
	}
	if ((char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

void	*ft_memcpy_gnl(void *dest, const void *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)dest;
	p2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*p1 = *p2;
		p1++;
		p2++;
		i++;
	}
	return (dest);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*arr;
	size_t	len;

	len = 0;
	if (!s)
		return (NULL);
	while (len < n && s[len])
		len++;
	if (len > SIZE_MAX - 1)
		return (NULL);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy_gnl(arr, s, len);
	arr[len] = '\0';
	return (arr);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin_alpha(char *va_buf, char *tmp)
{
	char	*arr;
	size_t	va_buf_len;
	size_t	tmp_len;

	va_buf_len = ft_strlen_gnl(va_buf);
	tmp_len = ft_strlen_gnl(tmp);
	arr = malloc(sizeof(char) * (va_buf_len + tmp_len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy_gnl(arr, va_buf, va_buf_len);
	ft_memcpy_gnl(arr + va_buf_len, tmp, tmp_len);
	arr[va_buf_len + tmp_len] = '\0';
	return (arr);
}
