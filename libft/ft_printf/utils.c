/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:39:01 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 17:01:07 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	put_nspace(t_info *inf, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_putchar(' ', inf) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	put_nstr(const char *str, size_t n, t_info *inf)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_putchar(*str++, inf) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	put_nzero(t_info *inf, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_putchar('0', inf) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	calc_maxlen(size_t *max_len, t_info *inf, const char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (inf->precision >= 0)
	{
		if (inf->precision < (int)str_len)
			*max_len = inf->precision;
		else
			*max_len = str_len;
	}
	else
		*max_len = str_len;
}

void	calc_pad(size_t *pad, t_info *inf, size_t max_len)
{
	if (inf->width >= max_len)
		*pad = inf->width - max_len;
	else
		*pad = 0;
}
