/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:31:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 13:03:05 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(t_args args, char **argv, char **path)
{
	char	*full_path;
	int		i;
	int		f;

	f = 0;
	i = 0;
	check_cmd(argv, path);
	while (path[i])
	{
		full_path = join_cmd(path[i], argv[0]);
		if (!full_path)
		{
			i++;
			continue ;
		}
		execve(full_path, argv, args.envp);
		if (errno == EACCES || errno == EPERM || errno == EISDIR)
			f = 1;
		free(full_path);
		i++;
	}
	exec_exit_proc(argv, path, f);
}

void	heredoc_manage_exec(t_args args, int ind)
{
	char	**argv;
	char	**path;

	argv = ft_split(args.av[3 + ind], ' ');
	if (!argv)
		_exit(127);
	if (ft_strchr(args.av[3 + ind], '/'))
	{
		execve(argv[0], argv, args.envp);
		free_split(argv);
		if (errno == EACCES || errno == EPERM || errno == EISDIR)
			exit_cmd_err(argv[0], 126);
		exit_cmd_err(argv[0], 127);
	}
	else
	{
		path = search_path(args.envp);
		if (!path)
		{
			free_split(argv);
			_exit(127);
		}
		exec_cmd(args, argv, path);
	}
}

void	manage_exec(t_args args, int ind)
{
	char	**argv;
	char	**path;

	argv = ft_split(args.av[2 + ind], ' ');
	if (!argv)
		_exit(127);
	if (ft_strchr(args.av[2 + ind], '/'))
	{
		execve(argv[0], argv, args.envp);
		free_split(argv);
		if (errno == EACCES || errno == EPERM || errno == EISDIR)
			exit_cmd_err(argv[0], 126);
		exit_cmd_err(argv[0], 127);
	}
	else
	{
		path = search_path(args.envp);
		if (!path)
		{
			free_split(argv);
			exit_cmd_err(argv[0], 127);
		}
		exec_cmd(args, argv, path);
	}
}
