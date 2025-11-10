/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:53 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/11 01:22:21 by kesaitou         ###   ########.fr       */
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

#endif