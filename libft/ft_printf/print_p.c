/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:37:52 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 05:53:41 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	print_p(va_list *args, t_info *inf, const char *base)
{
	char	*num_arr;
	size_t	prec_zero;
	size_t	hash;

	hash = 2;
	prec_zero = 0;
	num_arr = ft_uptoa_base(va_arg(*args, void *), base);
	if (!num_arr)
		return (ERROR);
	if (ft_strcmp(num_arr, "(nil)") == 0)
		hash = 0;
	if (inf->precision == 0 && ft_strcmp(num_arr, "0") == 0)
		num_arr[0] = '\0';
	else if ((int)ft_strlen(num_arr) < inf->precision)
		prec_zero = inf->precision - (int)ft_strlen(num_arr);
	if (p_print_process(num_arr, inf, hash, prec_zero) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

char	*ft_uptoa_base(void *ptr, const char *base)
{
	char		*num_arr;
	size_t		num_len;
	size_t		base_len;
	uintptr_t	num;

	if (ptr == 0)
		return (ft_strdup("(nil)"));
	num = (uintptr_t)ptr;
	base_len = ft_strlen(base);
	num_len = count_len_ptr(num, base_len);
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

int	p_print_process(char *num_arr, t_info *inf, size_t hash, size_t zero)
{
	size_t	num_len;
	size_t	pad;

	num_len = ft_strlen(num_arr);
	calc_pad(&pad, inf, num_len + hash + zero);
	if (right_align(inf, pad) == ERROR)
		return (ERROR);
	if (print_hash(inf, hash) == ERROR)
		return (ERROR);
	if (put_nzero(inf, zero) == ERROR)
		return (ERROR);
	if (put_nstr(num_arr, num_len, inf) == ERROR)
		return (ERROR);
	if (inf->flags & F_MINUS && put_nspace(inf, pad) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

size_t	count_len_ptr(uintptr_t num, size_t base_len)
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
