/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:22:13 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 05:42:42 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_key(char *line, char *av)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(line);
	len2 = ft_strlen(av);
	if (len1 == len2 + 1 && line[len2] == '\n' && !ft_strncmp(line, av, len2))
		return (1);
	if (len1 == len2 && !ft_strncmp(line, av, len2))
		return (1);
	return (0);
}

void	child_here_doc(t_args args, int *p)
{
	char	*tmp;

	while (1)
	{
		ft_printf("heredoc> ");
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (check_key(tmp, args.av[2]))
		{
			free(tmp);
			break ;
		}
		write(p[1], tmp, ft_strlen(tmp));
		free(tmp);
	}
	close(p[1]);
	_exit(0);
}

int	parent_here_doc(t_args *args, int *p, int pid)
{
	int	stat;

	close(p[1]);
	waitpid(pid, &stat, 0);
	if (WIFSIGNALED(stat) && WTERMSIG(stat) == SIGINT)
	{
		close(p[0]);
		return (ERROR);
	}
	args->in_fd = p[0];
	return (SUCCESS);
}

int	heredoc_fork_process(t_args args)
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
	close(args.ou_fd);
	if (proc.prev_read != -1)
		close(proc.prev_read);
	return (wait_process(proc));
}

int	here_doc(t_args *args)
{
	int		p[2];
	pid_t	pid;

	if (pipe(p) == -1)
		return (ERROR);
	pid = fork();
	if (pid < 0)
		return (ERROR);
	if (pid == 0)
	{
		close(p[0]);
		child_here_doc(*args, p);
	}
	return (parent_here_doc(args, p, pid));
}
