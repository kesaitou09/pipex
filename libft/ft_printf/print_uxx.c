/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:54 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 05:53:43 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	print_u(t_info *inf, va_list *args)
{
	size_t	prec_zero;
	char	*num_arr;

	prec_zero = 0;
	num_arr = utoa_hub(args, "0123456789");
	if (!num_arr)
		return (ERROR);
	if (inf->precision == 0 && ft_strcmp(num_arr, "0") == 0)
		num_arr[0] = '\0';
	if ((int)ft_strlen(num_arr) < inf->precision)
		prec_zero = inf->precision - ft_strlen(num_arr);
	if (u_print_process(num_arr, inf, 0, prec_zero) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

int	print_x(t_info *inf, va_list *args)
{
	size_t	hash_len;
	size_t	prec_zero;
	char	*num_arr;

	hash_len = 0;
	prec_zero = 0;
	num_arr = utoa_hub(args, "0123456789abcdef");
	if (!num_arr)
		return (ERROR);
	if (inf->precision == 0 && ft_strcmp(num_arr, "0") == 0)
		num_arr[0] = '\0';
	else if ((int)ft_strlen(num_arr) < inf->precision)
		prec_zero = inf->precision - (int)ft_strlen(num_arr);
	if ((inf->flags & F_HASH) && num_arr[0] != '0' && num_arr[0] != '\0')
		hash_len = 2;
	if (u_print_process(num_arr, inf, hash_len, prec_zero) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

int	print_lx(t_info *inf, va_list *args)
{
	size_t	hash_len;
	size_t	prec_zero;
	char	*num_arr;

	hash_len = 0;
	prec_zero = 0;
	num_arr = utoa_hub(args, "0123456789ABCDEF");
	if (!num_arr)
		return (ERROR);
	if (inf->precision == 0 && ft_strcmp(num_arr, "0") == 0)
		num_arr[0] = '\0';
	else if ((int)ft_strlen(num_arr) < inf->precision)
		prec_zero = inf->precision - (int)ft_strlen(num_arr);
	if ((inf->flags & F_HASH) && num_arr[0] != '0' && num_arr[0] != '\0')
		hash_len = 2;
	if (u_print_process(num_arr, inf, hash_len, prec_zero) == ERROR)
		return (free(num_arr), ERROR);
	return (free(num_arr), SUCCESS);
}

int	u_print_process(char *num_arr, t_info *inf, size_t hash, size_t zero)
{
	size_t	num_len;
	size_t	pad;

	num_len = ft_strlen(num_arr);
	calc_pad(&pad, inf, num_len + hash + zero);
	if (!(inf->flags & F_MINUS))
	{
		if (inf->flags & F_ZERO && inf->precision == -1)
		{
			if (put_nzero(inf, pad) == ERROR)
				return (ERROR);
		}
		else if (put_nspace(inf, pad) == ERROR)
			return (ERROR);
	}
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

int	print_hash(t_info *inf, size_t hash)
{
	if (hash)
	{
		if (inf->specifier == 'x' || inf->specifier == 'p')
		{
			if (ft_putstr("0x", inf) == ERROR)
				return (ERROR);
		}
		if (inf->specifier == 'X')
		{
			if (ft_putstr("0X", inf) == ERROR)
				return (ERROR);
		}
	}
	return (SUCCESS);
}
