/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:45 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:00:41 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"


void	parse_flag(const char **format, t_info *inf)
{
	while (is_flag(**format))
	{
		if (**format == '+')
			inf->flags |= F_PLUS;
		else if (**format == '-')
			inf->flags |= F_MINUS;
		else if (**format == ' ')
			inf->flags |= F_SPACE;
		else if (**format == '0')
			inf->flags |= F_ZERO;
		else if (**format == '#')
			inf->flags |= F_HASH;
		(*format)++;
	}
	if (inf->flags & F_PLUS)
		inf->flags &= ~F_SPACE;
	if (inf->flags & F_MINUS)
		inf->flags &= ~F_ZERO;
}

void	parse_width(const char **format, t_info *inf)
{
	if (**format == '0')
		return ;
	inf->width = ft_atoi_alpha((const char **)format);
}

void	parse_precision(const char **format, t_info *inf)
{
	if (**format == '.')
	{
		(*format)++;
		inf->precision = ft_atoi_alpha((const char **)format);
	}
}

void	parse_specifi(const char **format, t_info *inf)
{
	if (ft_strchr("cspdiuxX%", **format))
		inf->specifier = **format;
	(*format)++;
}
