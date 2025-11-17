/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:18 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 12:59:36 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # define OPEN_MAX 65534
# define OPEN_MAX 10240
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen_gnl(const char *s);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_alpha(char *va_buf, char *tmp);
char	*ft_strndup(char *s, size_t n);

char	*get_next_line(int fd);

#endif