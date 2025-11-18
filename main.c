/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/18 10:54:26 by kesaitou         ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	t_args	args;

	if (ac < 4)
		return (0);
	init_args(&args, ac, av, envp);
	return (branch_process(args));
}
