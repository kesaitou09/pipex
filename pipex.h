/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:53 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/12 07:19:59 by kesaitou         ###   ########.fr       */
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

typedef enum e_flag
{
	ST_BASE = 1 << 0,
	ST_SQ = 1 << 1,
	ST_DQ = 1 << 2,
	ST_ESC = 1 << 3,
	ST_HEREDQ = 1 << 4,
}					t_flag;



#endif