/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 05:40:00 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/18 10:44:31 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipe_stdin(t_args args, t_proc proc, int i)
{
	if (i == 0)
	{
		if (args.in_fd != -1 && dup2(args.in_fd, STDIN_FILENO) == -1)
			_exit(1);
	}
	else
	{
		if (dup2(proc.prev_read, STDIN_FILENO) == -1)
			_exit(1);
	}
}

static void	pipe_stdout(t_args args, t_proc proc, int i)
{
	if (i < proc.cmds - 1)
	{
		if (dup2(proc.p[1], STDOUT_FILENO) == -1)
			_exit(1);
	}
	else
	{
		if (args.ou_err)
		{
			close(proc.p[0]);
			_exit(1);
		}
		if (args.ou_fd != -1)
		{
			if (dup2(args.ou_fd, STDOUT_FILENO) == -1)
				_exit(1);
		}
		else
			_exit(1);
	}
}

void	child_infile_err(t_proc proc, t_args args, int i)
{
	if (proc.prev_read != -1)
		close(proc.prev_read);
	if (i < proc.cmds - 1)
	{
		close(proc.p[0]);
		close(proc.p[1]);
	}
	if (args.in_fd != -1)
		close(args.in_fd);
	if (args.ou_fd != -1)
		close(args.ou_fd);
	_exit(1);
}

void	child_process(t_proc proc, t_args args, int i)
{
	if (i == 0 && args.in_err)
		child_infile_err(proc, args, i);
	pipe_stdin(args, proc, i);
	pipe_stdout(args, proc, i);
	if (proc.prev_read != -1)
		close(proc.prev_read);
	if (i < proc.cmds - 1)
	{
		close(proc.p[0]);
		close(proc.p[1]);
	}
	if (args.in_fd != -1)
		close(args.in_fd);
	if (args.ou_fd != -1)
		close(args.ou_fd);
	manage_exec(args, i);
}

void	heredoc_child_process(t_proc proc, t_args args, int i)
{
	pipe_stdin(args, proc, i);
	pipe_stdout(args, proc, i);
	if (proc.prev_read != -1)
		close(proc.prev_read);
	if (i < proc.cmds - 1)
	{
		close(proc.p[0]);
		close(proc.p[1]);
	}
	if (args.in_fd != -1)
		close(args.in_fd);
	if (args.in_fd != -1)
		close(args.ou_fd);
	heredoc_manage_exec(args, i);
}
