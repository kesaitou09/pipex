/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:05:07 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/18 09:33:29 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_heredoc(t_args *args, int ac, char **av)
{
	if (!ft_strcmp("here_doc", av[1]))
	{
		args->in_fd = -1;
		args->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (args->ou_fd == -1)
		{
			print_errno_err(av[ac - 1]);
			args->ou_err = 1;
		}
	}
}

void	init_normal(t_args *args, int ac, char **av)
{
	args->in_fd = open(av[1], O_RDONLY);
	if (args->in_fd == -1)
	{
		print_errno_err(av[1]);
		args->in_err = 1;
	}
	args->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (args->ou_fd == -1)
	{
		print_errno_err(av[ac - 1]);
		args->ou_err = 1;
	}
}

void	init_args(t_args *args, int ac, char **av, char **envp)
{
	args->ac = ac;
	args->av = av;
	args->envp = envp;
	args->in_err = 0;
	args->ou_err = 0;
	if (!ft_strcmp("here_doc", av[1]))
		init_heredoc(args, ac, av);
	else
		init_normal(args, ac, av);
}
