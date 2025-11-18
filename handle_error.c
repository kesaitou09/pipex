/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:59:33 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/18 18:59:24 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_cmd_err(char *cmd, int status)
{
	if (status == 126)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else if (status == 127)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
	}
	exit(status);
}

void	print_errno_err(char *target)
{
	int	err;

	err = errno;
	ft_putstr_fd("pipex: ", 2);
	if (target)
	{
		ft_putstr_fd(target, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(strerror(err), 2);
}

void	exit_cmd_err(char *cmd, int status)
{
	print_cmd_err(cmd, status);
	exit(status);
}

void	exit_errno_err(char *target, int status)
{
	print_errno_err(target);
	exit(status);
}
