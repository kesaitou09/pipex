/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:38:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 05:53:32 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_putchar(char c, t_info *inf)
{
	if (write(1, &c, 1) == ERROR)
		return (ERROR);
	inf->total_len += 1;
	return (SUCCESS);
}

int	ft_putstr(char *str, t_info *inf)
{
	while (*str)
	{
		if (ft_putchar(*str++, inf) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strncmp(s1, s2, ft_strlen(s1)));
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}

int	is_flag(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '#')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int	ft_atoi_alpha(const char **nptr)
{
	int	result;

	result = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		result = result * 10 + (**nptr - '0');
		(*nptr)++;
	}
	return (result);
}
