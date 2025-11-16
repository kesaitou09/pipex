/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:31:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 05:11:35 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	exec_cmd(t_args args, char **argv, char **path)
{
	char	*full_path;
	int		i;
	int		f;

	f = 0;
	i = 0;
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
	free_split(path);
	free_split(argv);
	if (f)
		exit_cmd_err(argv[0], 126);
	exit_cmd_err(argv[0], 127);
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
