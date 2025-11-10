/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaitou <ksaitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:18 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/01 19:52:43 by ksaitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # define OPEN_MAX 65534
#define OPEN_MAX 10240
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen_gnl(const char *s);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_alpha(char *va_buf, char *tmp);
char	*ft_strndup(char *s, size_t n);

char	*my_get_line(char **va_buf);
char	*get_next_line(int fd);
char	*read_file(int fd, char *va_buf);
char	*dup_line(char **va_buf);

#endif