/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:35:22 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/17 13:00:23 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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

void	dup_line(char ***va_buf, char **line, size_t len, size_t rest_len)
{
	char	*old;
	char	*rest;

	while ((**va_buf)[len] != '\0' && (**va_buf)[len] != '\n')
		len++;
	if ((**va_buf)[len] == '\n')
		*line = ft_strndup(**va_buf, len + 1);
	else
		*line = ft_strndup(**va_buf, len);
	if (!line)
		return ;
	if ((**va_buf)[len] == '\n')
	{
		rest_len = ft_strlen_gnl((**va_buf) + len + 1);
		if (rest_len > 0)
			rest = ft_strndup((**va_buf) + len + 1, rest_len);
		else
			rest = NULL;
	}
	else
		rest = NULL;
	old = **va_buf;
	**va_buf = rest;
	free(old);
}

char	*manage_dup_line(char **va_buf)
{
	char	*line;
	size_t	len;
	size_t	rest_len;

	len = 0;
	rest_len = 0;
	dup_line(&va_buf, &line, len, rest_len);
	return (line);
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
	return (manage_dup_line(va_buf));
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
