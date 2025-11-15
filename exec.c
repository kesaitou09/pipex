/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:31:37 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/13 18:32:56 by kesaitou         ###   ########.fr       */
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
	while (path[i])
	{
		full_path = join_cmd(path[i], argv[0]);
		if (!full_path)
			continue ;
		execve(full_path, argv, args.envp);
		if (errno == EACCES || errno == EPERM || errno == EISDIR)
			f = 1;
		free(full_path);
		i++;
	}
	free_split(path);
	free_split(argv);
	if (f)
		_exit(126);
	_exit(127);
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
			_exit(126);
		_exit(127);
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
