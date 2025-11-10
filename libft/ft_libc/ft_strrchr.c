/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:25 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/16 02:11:49 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	if ((char)c == '\0')
		return ((char *)(p));
	while (s < p)
	{
		if (*(p - 1) == (char)c)
		{
			return ((char *)(p - 1));
		}
		p--;
	}
	return (NULL);
}

// int main(void)
//{
//	printf("%s\n",strrchr("abbaaaaabbaifififohf ",'a'));
//	printf("%s\n",ft_strrchr("abbaaaaabbaifififohf ",'a'));
//	printf("%s\n",strrchr("abbaaaaabbaifififohf",'a'));
// }