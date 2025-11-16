/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:45 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

//#include <stdio.h>
//#include <string.h>
// int main(void)
//{
//	//printf("%s\n",ft_strdup(""));
//	printf("%p\n",strdup(NULL));
//	//関数内部でセグフォ出してるから未定義
// }