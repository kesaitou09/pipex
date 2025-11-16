/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 05:40:00 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 05:43:12 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	child_pipeline(t_args args, t_proc proc, int i)
{
	if (i == 0)
	{
		if (dup2(args.in_fd, STDIN_FILENO) == -1)
			_exit(1);
	}
	else
	{
		if (dup2(proc.prev_read, STDIN_FILENO) == -1)
			_exit(1);
	}
	if (i < proc.cmds - 1)
	{
		if (dup2(proc.p[1], STDOUT_FILENO) == -1)
			_exit(1);
	}
	else
	{
		if (dup2(args.ou_fd, STDOUT_FILENO) == -1)
			_exit(1);
	}
}

void	child_process(t_proc proc, t_args args, int i)
{
	child_pipeline(args, proc, i);
	if (proc.prev_read != -1)
		close(proc.prev_read);
	if (i < proc.cmds - 1)
	{
		close(proc.p[0]);
		close(proc.p[1]);
	}
	close(args.ou_fd);
	manage_exec(args, i);
}

void	heredoc_child_process(t_proc proc, t_args args, int i)
{
	child_pipeline(args, proc, i);
	if (proc.prev_read != -1)
		close(proc.prev_read);
	if (i < proc.cmds - 1)
	{
		close(proc.p[0]);
		close(proc.p[1]);
	}
	close(args.ou_fd);
	heredoc_manage_exec(args, i);
}
