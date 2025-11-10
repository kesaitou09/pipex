/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/10 21:14:54 by kesaitou         ###   ########.fr       */
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

int	exex_cmd(char *av, char **envp)
{
	char	**path;
	char	**argv;
	char	*full_path;
	int		i;

	argv = ft_split(av, ' ');
	if (!argv)
		return (1);
	path = search_path(envp);
	if (!path)
		return (1);
	i = 0;
	while (path[i])
	{
		full_path = join_cmd(path[i], argv[0]);
		if (!full_path)
			return (1);
		execve(full_path, argv, envp);
		i++;
	}
	return (1);
}

int	fork_process(char *av, char **envp, int in_fd, int ou_fd)
{
	int	pid;

	if (in_fd == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		if (dup2(in_fd, STDIN_FILENO) == -1)
			_exit(1);
		close(in_fd);
		exex_cmd(av, envp);
		_exit(126);
	}
}

int	child_process()
{
	
	
	
	
	
	
	
}

int	branch_process(int ac, char **av, char **envp)
{
	int	i;
	int	in_fd;
	int	pid;
	int	ou_fd;
	int	p[2];

	if (!ft_strcmp(av[1], "here_doc"))
		return (0);
	else
	{
		in_fd = open(av[1], O_RDONLY);
		ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		i = 2;
		while (i < ac - 2)
		{
			if (!(i == 2 || i == ac - 2))
			{
				if (pipe(p) == -1)
					return (1);
			}
			fork_process(av[i], envp, in_fd, ou_fd);
			
		}
	}
	close(in_fd);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (branch_process(ac, av, envp) == 1)
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
		[2] [3] [4] [5]
ac = 7
i = 2
i < ac - 2
*/
