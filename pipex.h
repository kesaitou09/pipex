/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:53 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/18 09:06:02 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**envp;
	char	*here_input;
	int		in_fd;
	int		ou_fd;
	int		in_err;
	int		ou_err;

}			t_args;

typedef struct s_proc
{
	pid_t	pid;
	pid_t	last_pid;
	int		p[2];
	int		prev_read;
	int		cmds;

}			t_proc;

void		init_heredoc(t_args *args, int ac, char **av);
void		init_normal(t_args *args, int ac, char **av);
void		init_args(t_args *args, int ac, char **av, char **envp);

void		exec_cmd(t_args args, char **argv, char **path);
void		manage_exec(t_args args, int ind);
char		**search_path(char **envp);
char		*join_cmd(char *path, char *cmd);

void		free_two(void *ptr1, void *ptr2);
void		free_split(char **s);

int			fork_process(t_args args);
void		init_proc(t_proc *proc, t_args args);

void		parent_process(t_proc *proc, int i);
int			wait_process(t_proc proc);
void		exit_cmd_err(char *cmd, int status);
void		exit_errno_err(char *target, int status);
void		print_errno_err(char *target);

char		**search_path(char **envp);
char		*join_cmd(char *path, char *cmd);
void		check_cmd(char **argv, char **path);
void		exec_exit_proc(char **argv, char **path, int f);

void		child_process(t_proc proc, t_args args, int i);
void		heredoc_child_process(t_proc proc, t_args args, int i);
int			here_doc(t_args *args);
int			heredoc_fork_process(t_args args);
int			parent_here_doc(t_args *args, int *p, int pid);
void		child_here_doc(t_args args, int *p);
void		heredoc_manage_exec(t_args args, int ind);

#endif