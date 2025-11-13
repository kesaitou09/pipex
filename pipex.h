/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:53 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/13 15:16:23 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>

typedef struct s_args
{
	int		ac;
	char	**av;
	char	**envp;
	int		in_fd;
	int		ou_fd;

}			t_args;

typedef struct s_proc
{
	pid_t	pid;
	pid_t	last_pid;
	int		p[2];
	int		prev_read;
	int		cmds;
	
}t_proc;



#endif