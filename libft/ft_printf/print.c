/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:37:55 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:00:57 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"


int	print_hub(va_list *args, t_info *inf)
{
	if (inf->specifier == 'c' || inf->specifier == '%')
		return (print_cper(args, inf));
	else if (inf->specifier == 's')
		return (print_s(args, inf));
	else if (inf->specifier == 'd' || inf->specifier == 'i')
		return (print_di(inf, args));
	else if (inf->specifier == 'u')
		return (print_u(inf, args));
	else if (inf->specifier == 'x')
		return (print_x(inf, args));
	else if (inf->specifier == 'X')
		return (print_lx(inf, args));
	else if (inf->specifier == 'p')
		return (print_p(args, inf, "0123456789abcdef"));
	return (SUCCESS);
}
