/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:14 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)(big));
	little_len = ft_strlen(little);
	while (*big && i < len && little_len <= len - i)
	{
		if (!ft_strncmp(big, little, little_len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}

// int	main(void)
//{
//	printf("libc %s\n", strnstr("abcdefhfiaefj", NULL, 30));
//	printf("my %s\n", ft_strnstr("abcdefhfiaefj", NULL, 30));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
//		printf("%s\n",strnstr("abcdefhijk","de",3));
// }