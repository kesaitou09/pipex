/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 21:37:12 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_proc(t_proc *proc, t_args args)
{
	if (!ft_strcmp(args.av[1], "here_doc"))
		proc->cmds = args.ac - 4;
	else
		proc->cmds = args.ac - 3;
	proc->last_pid = -1;
	proc->prev_read = -1;
	proc->pid = -1;
}

int	branch_process(t_args args)
{
	if (!ft_strcmp(args.av[1], "here_doc"))
	{
		if (here_doc(&args) == ERROR)
		{
			return (1);
		}
		return (heredoc_fork_process(args));
	}
	else
		return (fork_process(args));
}

int	init_args(t_args *args, int ac, char **av, char **envp)
{
	args->ac = ac;
	args->av = av;
	args->envp = envp;
	if (!ft_strcmp("here_doc", av[1]))
	{
		args->in_fd = -1;
		args->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (args->ou_fd == -1)
			return (print_errno_err(av[ac - 1]), ERROR);
	}
	else
	{
		args->in_fd = open(av[1], O_RDONLY);
		if (args->in_fd == -1)
			return (print_errno_err(av[1]), ERROR);
		args->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (args->ou_fd == -1)
			return (print_errno_err(av[ac - 1]), ERROR);
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_args	args;

	if (init_args(&args, ac, av, envp) == ERROR)
		return (1);
	return (branch_process(args));
}
