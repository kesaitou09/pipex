/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:48 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:00:44 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"


int	print_cper(va_list *args, t_info *inf)
{
	unsigned char	c;
	size_t			pad;

	if (inf->specifier == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(*args, int);
	(void)args;
	calc_pad(&pad, inf, 1);
	if (inf->flags & F_MINUS)
	{
		if (ft_putchar(c, inf) == ERROR)
			return (ERROR);
		if (put_nspace(inf, pad) == ERROR)
			return (ERROR);
	}
	else
	{
		if (put_nspace(inf, pad) == ERROR)
			return (ERROR);
		if (ft_putchar(c, inf) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	print_s(va_list *args, t_info *inf)
{
	const char	*str;
	size_t		max_len;
	size_t		pad;

	str = va_arg(*args, const char *);
	if (str == NULL)
		str = "(null)";
	calc_maxlen(&max_len, inf, str);
	calc_pad(&pad, inf, max_len);
	if (!(inf->flags & F_MINUS))
	{
		if (put_nspace(inf, pad) == ERROR)
			return (ERROR);
	}
	if (put_nstr(str, max_len, inf) == ERROR)
		return (ERROR);
	if (inf->flags & F_MINUS)
	{
		if (put_nspace(inf, pad) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
