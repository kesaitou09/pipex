/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/10 06:30:50 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char **search_path(char **envp)
{
	int	i;
	char	*full_path;

	i = 0;
	full_path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			full_path = envp[i] + 5;
			break;
		}
		i++;
	}
	if (full_path)
		return (ft_split(full_path, ':'));
	return (NULL);
}

char	*join_cmd(char *path, char *cmd)
{
	char *tmp;
	char *joined;

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

char	*join_args()
{
	
	
	
	
	
}

int	exex_cmd(char **path, char *cmd, char **env)
{

	
	
}

int	branch_process(int ac, char **av, char **envp)
{
	int in_fd;
	int	ou_fd;

	if (!ft_strcmp(av[1], "here_doc"))
		return (0);
	else
	{
		in_fd = open(av[1], O_RDONLY);
		ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 644);
		if (in_fd == -1 || ou_fd == -1)
			return (1);
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
}

int	main(int ac, char **av, char **envp)
{
	int	pid;
	char **path;

	path = search_path(envp);
	pid = fork;
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		exex_cmd(path, av[1], envp);
		
		
	}
	
	
	fork
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
