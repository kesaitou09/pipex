/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:42 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:01:15 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

char	*utoa_hub(va_list *args, const char *base)
{
	unsigned long long	num;

	num = va_arg(*args, unsigned int);
	return (ft_utoa_base(num, base));
}

char	*ft_utoa_base(unsigned long long num, const char *base)
{
	char	*num_arr;
	size_t	num_len;
	size_t	base_len;

	base_len = ft_strlen(base);
	num_len = count_len(num, base_len);
	num_arr = malloc(sizeof(char) * (num_len + 1));
	if (!num_arr)
		return (NULL);
	num_arr[num_len] = '\0';
	while (num_len)
	{
		num_arr[--num_len] = base[num % base_len];
		num /= base_len;
	}
	return (num_arr);
}

size_t	count_len(unsigned long long num, size_t base_len)
{
	size_t	len;

	len = 0;
	if (!num)
		len++;
	while (num)
	{
		len++;
		num /= base_len;
	}
	return (len);
}
