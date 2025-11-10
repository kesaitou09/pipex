/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:36 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:00:31 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	init_info(t_info *inf)
{
	inf->flags = 0;
	inf->width = -1;
	inf->precision = -1;
	inf->specifier = 0;
}

int	parse_hub(const char **format, t_info *inf, va_list *args)
{
	(*format)++;
	if (!**format)
		return (ERROR);
	init_info(inf);
	parse_flag(format, inf);
	parse_width(format, inf);
	parse_precision(format, inf);
	parse_specifi(format, inf);
	if (print_hub(args, inf) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	parse(const char **format, t_info *inf, va_list *args)
{
	while (**format)
	{
		if (**format == '%')
		{
			if (parse_hub(format, inf, args) == ERROR)
				return (ERROR);
		}
		else
		{
			if (ft_putchar(**format, inf) == ERROR)
				return (ERROR);
			(*format)++;
		}
	}
	return (SUCCESS);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_info	inf;

	inf.total_len = 0;
	va_start(args, format);
	init_info(&inf);
	if (parse(&format, &inf, &args) == ERROR)
		return (va_end(args), ERROR);
	va_end(args);
	return (inf.total_len);
}
