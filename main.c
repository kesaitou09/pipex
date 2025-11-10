/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/11 03:11:38 by kesaitou         ###   ########.fr       */
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

int	exex_cmd(t_args args, int ind)
{
	char	**path;
	char	**argv;
	char	*full_path;
	int		i;

	argv = ft_split(args.av[ind], ' ');
	if (!argv)
		return (1);
	path = search_path(args.envp);
	if (!path)
		return (1);
	i = 0;
	while (path[i])
	{
		full_path = join_cmd(path[i], argv[ind]);
		if (!full_path)
			return (1);
		execve(full_path, argv, args.envp);
		i++;
	}
	return (1);
}

int	fork_process(t_args args)
{
	pid_t	pid;
	int		p[2];
	int		i;
	int		prev_read;
	pid_t	last_pid;

	i = 0;
	prev_read = -1;
	last_pid = -1;
	while (i < args.ac - 2)
	{
		if (i < args.ac - 3)
			pipe(p);
		pid = fork();
		if (pid < 0)
			return (1);
		else if (pid == 0)
		{
			if (i == 0)
			{
				if (dup2(args.in_fd, STDIN_FILENO) == -1)
					_exit(1);
				close(args.in_fd);
				exex_cmd(args, i);
					_exit(126);
			}
			else
			{
				if (dup2(prev_read, STDIN_FILENO) == -1)
					_exit(1);
				close(args.in_fd);
				exex_cmd(args, i);
					_exit(126);
			}
			if (i < args.ac - 2)
			{
				if (dup2(p[1], STDOUT_FILENO) == -1)
					_exit(1);
			}
			else
			{
				if (dup2(args.ou_fd, STDOUT_FILENO) == -1)
					_exit(1);
			}
			if (prev_read != -1)
				close(prev_read);
			if (i < args.ac - 2)
			{
				close(p[0]);
				close(p[1]);
			}
			close(args.in_fd);
			close(args.ou_fd);
			exex_cmd(args, i);
			_exit(126);
						
		}
		if (prev_read != -1)
			close(prev_read);
		if (i < args.ac - 2)
		{
			close(p[1]);
			prev_read = p[0];
		}
		if (i == args.ac - 2)
			last_pid = pid;
		i++;
	}
	close(args.in_fd);
	close(args.ou_fd);
	if (prev_read != -1)
		close(prev_read);
	
	int st, exitcode = 1;
    for (int k = 0; k < args.ac - 2; k++) {
        pid_t w = wait(&st);
        if (w == -1) { perror("wait"); break; }
        if (w == last_pid) {
            if (WIFEXITED(st))      exitcode = WEXITSTATUS(st);
            else if (WIFSIGNALED(st)) exitcode = 128 + WTERMSIG(st);
        }
    }
    return exitcode;
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
