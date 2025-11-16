/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:57:21 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 04:11:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

// int	main(void)
// {
// 	int x = 4299;
// 	int y = 0;
// 	ft_memcpy(&x, &x, 4);
// 	printf("%d\n", x);
// 	memcpy(&x, &x, 4);
// 	printf("%d\n", x);
// 	//ft_memcpy(&y, &x, 4);

// 	"abcdef"
// 	"01234"

// }