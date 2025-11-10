/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:08 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/17 08:28:44 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	size_t	i;

	arr = ft_strdup(s);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = (f)(i, s[i]);
		i++;
	}
	return (arr);
}
