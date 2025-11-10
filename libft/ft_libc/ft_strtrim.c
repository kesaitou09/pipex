/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:28 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/17 13:48:24 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n);
static int		is_set(char const *set, char c);
static char		*ft_strndup(const char *s, size_t n);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		s1_len;
	const char	*end;

	s1_len = ft_strlen(s1);
	end = s1 + s1_len;
	while (*s1 && is_set(set, *s1))
		s1++;
	while (s1 < end && is_set(set, *(end - 1)))
		end--;
	return (ft_strndup(s1, end - s1));
}

static int	is_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
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

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (s[len] && len < n)
		len++;
	return (len);
}

// int	main(void)
//{
//	printf("%s\n", ft_strtrim("\n\n\njjjjaaaaabbffnejhjehkj\n\n\n", " \n"));
// }