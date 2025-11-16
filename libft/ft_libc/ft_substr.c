/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:31 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_strnlen(const char *s, size_t n);
static char		*ft_strndup(const char *s, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_len = ft_strnlen(&s[start], len);
	return (ft_strndup(&s[start], sub_len));
}

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (s[len] && len < n)
		len++;
	return (len);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*arr;
	size_t	len;

	len = ft_strnlen(s, n);
	if (len > SIZE_MAX - 1)
		return (NULL);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_memcpy(arr, s, len);
	arr[len] = '\0';
	return (arr);
}

// int	main(void)
//{
//	printf("%s\n", ft_substr("abcdefg", 2, strnlen("abcdeefg", 20)));
// }