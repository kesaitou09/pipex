/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:39 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/17 09:00:14 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c);
static void		free_split(char **s);
static char		*alloc_string(char const *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = alloc_string(s, c);
			if (!arr[i++])
				return (free_split(arr), NULL);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

static size_t	count_words(const char *s, char c)
{
	size_t	len;
	size_t	in_word;

	len = 0;
	in_word = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			len++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (len);
}

static char	*alloc_string(char const *str, char c)
{
	size_t	i;
	size_t	len;
	char	*arr;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

static void	free_split(char **s)
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

// #include <stdio.h>

// int	main(void)
// {
// 	char	**arr;

// 	arr = ft_split("auuuuhuihuhahuhuihuihahuhuhua   a    a", 'a');
// 	// printf("%zu", count_words("a n n nassk nnn", ' '));
// 	// printf("%p\n",ft_split("ABCDEF",'a')[1]);
// 	for (int i = 0; arr[i]; i++)
// 	{
// 		printf("%s\n", arr[i]);
// 	}
// 	free_split(arr);

// }
