/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:02:09 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/18 18:59:24 by kesaitou         ###   ########.fr       */
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

void	check_cmd(char **argv, char **path)
{
	if (!argv || !argv[0] || !argv[0][0])
	{
		ft_putstr_fd("pipex: command not found\n", STDERR_FILENO);
		free_split(argv);
		free_split(path);
		exit(127);
	}
}

void	exec_exit_proc(char **argv, char **path, int f)
{
	if (f)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putendl_fd(": Permission denied", STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	free_split(path);
	free_split(argv);
	if (f)
		exit(126);
	exit(127);
}
