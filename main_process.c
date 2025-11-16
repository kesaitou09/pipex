/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:31:51 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 05:14:46 by kesaitou         ###   ########.fr       */
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

int	wait_process(t_proc proc)
{
	int		i;
	int		stat;
	int		exit_code;
	pid_t	wpid;

	i = 0;
	exit_code = 1;
	while (i < proc.cmds)
	{
		wpid = wait(&stat);
		if (wpid == -1)
		{
			perror("wait");
			break ;
		}
		if (wpid == proc.last_pid)
		{
			if (WIFEXITED(stat))
				exit_code = WEXITSTATUS(stat);
			else if (WIFSIGNALED(stat))
				exit_code = 128 + WTERMSIG(stat);
		}
		i++;
	}
	return (exit_code);
}

void	parent_process(t_proc *proc, int i)
{
	if (proc->prev_read != -1)
		close(proc->prev_read);
	if (i < proc->cmds - 1)
	{
		close(proc->p[1]);
		proc->prev_read = proc->p[0];
	}
	if (i == proc->cmds - 1)
		proc->last_pid = proc->pid;
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

int	fork_process(t_args args)
{
	t_proc	proc;
	int		i;

	init_proc(&proc, args);
	i = 0;
	while (i < proc.cmds)
	{
		if (i < proc.cmds - 1)
			pipe(proc.p);
		proc.pid = fork();
		if (proc.pid < 0)
			return (1);
		else if (proc.pid == 0)
			child_process(proc, args, i);
		parent_process(&proc, i);
		i++;
	}
	close(args.in_fd);
	close(args.ou_fd);
	if (proc.prev_read != -1)
		close(proc.prev_read);
	return (wait_process(proc));
}
