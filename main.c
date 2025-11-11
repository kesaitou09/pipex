/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/12 03:17:26 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**search_path(char **envp)
{
	int		i;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			full_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (full_path)
		return (ft_split(full_path, ':'));
	return (NULL);
}

char	*join_cmd(char *path, char *cmd)
{
	char	*tmp;
	char	*joined;

	joined = ft_strjoin(path, "/");
	if (!joined)
		return (NULL);
	tmp = joined;
	joined = ft_strjoin(tmp, cmd);
	if (!joined)
		return (free(tmp), NULL);
	free(tmp);
	return (joined);
}

int	exec_cmd(t_args args, int ind)
{
	char	**path;
	char	**argv;
	char	*full_path;
	int		i;

	argv = ft_split(args.av[2 + ind], ' ');
	if (!argv)
		return (1);
	path = search_path(args.envp);
	if (!path)
		return (1);
	i = 0;
	while (path[i])
	{
		full_path = join_cmd(path[i], argv[0]);
		if (!full_path)
			return (1);
		execve(full_path, argv, args.envp);
		i++;
	}
	return (1);
}

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

void	init_proc(t_proc *proc, t_args args)
{
	proc->cmds = args.ac - 3;
	proc->last_pid = -1;
	proc->prev_read = -1;
	proc->pid = -1;
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
	close(args.in_fd);
	close(args.ou_fd);
	exec_cmd(args, i);
	_exit(126);
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

int	branch_process(t_args args)
{
	if (!ft_strcmp(args.av[1], "here_doc"))
		return (0);
	else
	{
		if (fork_process(args) == ERROR)
			return (ERROR);
	}
	return (0);
}

int	init_args(t_args *args, int ac, char **av, char **envp)
{
	args->ac = ac;
	args->av = av;
	args->envp = envp;
	args->in_fd = open(av[1], O_RDONLY);
	if (args->in_fd == -1)
		return (ERROR);
	args->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (args->ou_fd == -1)
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_args	args;

	if (init_args(&args, ac, av, envp) == ERROR)
		return (ERROR);
	if (branch_process(args) == 1)
		return (1);
}

/* ./pipex file1 cmd1 cmd2 file2
 ファイル１をcmd1に入力して
 cmd1を実行するためには子プロセスを作ってexecveをする必要がある
 cmd1を実行するにはフルパスを検索し、
 dir/av[i]の形式で全探索する必要がある
 av[2] ~ av[ac - 2]まで全探索すれば良い
 av[i] を空白でsplitする


file cmd cmd cmd cmd file
[0]		[1] [2] [3] [4] [5]
		[1] | [2] | [3] | [4] | [5]
		1    2     3     4    5

i = 1;
while(i < ac - 2)

fork()するタイミングとpipe()するタイミング
forkはコマンドを別プロセスで実行するために必要
pipeは入出力を制御するために必要
pipeは最後以外のコマンドを実行するタイミングで必要



ac = 7
i = 2
i < ac - 2
*/
