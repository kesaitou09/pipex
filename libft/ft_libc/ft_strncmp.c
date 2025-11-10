/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:58:11 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/17 13:56:11 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		}
		i++;
	}
	return (0);
}

// int main(void)
//{
//	printf("my %d\n",ft_strncmp("abo","ab",3));
//	printf("lib %d\n",strncmp("abo","ab",3));
//	printf("my %d\n",ft_strncmp("abc","ab",3));
//	printf("my %d\n",ft_strncmp("abc","ab",3));
//	printf("my %d\n",ft_strncmp("abc","ab",3));
// }