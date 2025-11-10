/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:22 by kesaitou          #+#    #+#             */
/*   Updated: 2025/10/29 20:55:23 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_gnl(const char *s);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_alpha(char *va_buf, char *tmp);
char	*ft_strndup(char *s, size_t n);

char	*read_file(int fd, char *va_buf)
{
	char	*tmp;
	char	*new_buf;
	int		rc;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	rc = 1;
	while (!ft_strchr_gnl(va_buf, '\n') && rc > 0)
	{
		rc = read(fd, tmp, BUFFER_SIZE);
		if (rc == -1)
			return (free(tmp), NULL);
		if (rc == 0)
			break ;
		tmp[rc] = '\0';
		new_buf = ft_strjoin_alpha(va_buf, tmp);
		if (!new_buf)
			return (free(tmp), NULL);
		free(va_buf);
		va_buf = new_buf;
	}
	free(tmp);
	return (va_buf);
}

char	*my_get_line(char **va_buf)
{
	if (*va_buf == NULL || **va_buf == '\0')
	{
		if (*va_buf)
		{
			free(*va_buf);
			*va_buf = NULL;
		}
		return (NULL);
	}
	return (dup_line(va_buf));
}

char	*dup_line(char **va_buf)
{
	char	*line;
	char	*rest;
	char	*old;
	size_t	len;

	len = 0;
	while ((*va_buf)[len] != '\0' && (*va_buf)[len] != '\n')
		len++;
	if ((*va_buf)[len] == '\n')
		line = ft_strndup(*va_buf, len + 1);
	else
		line = ft_strndup(*va_buf, len);
	if (!line)
		return (NULL);
	if ((*va_buf)[len] == '\n')
		rest = ft_strndup((*va_buf) + len + 1, ft_strlen_gnl((*va_buf) + len
					+ 1));
	else
		rest = NULL;
	old = *va_buf;
	*va_buf = rest;
	free(old);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*va_buf[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	res = read_file(fd, va_buf[fd]);
	if (!res)
	{
		free(va_buf[fd]);
		va_buf[fd] = NULL;
		return (NULL);
	}
	va_buf[fd] = res;
	return (my_get_line(&va_buf[fd]));
}
