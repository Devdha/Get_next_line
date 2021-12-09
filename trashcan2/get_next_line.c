/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:33:03 by dha               #+#    #+#             */
/*   Updated: 2021/12/09 20:04:41 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
			str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

static int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return (1);
		s++;
	}
	return (0);
}

static char	*get_line(char **backup, int fd)
{
	char	*line;
	char	*new_backup;
	int		i;

	i = 0;
	while (backup[fd][i])
	{
		if (backup[fd][i] == '\n')
			break ;
		i++;
	}
	line = ft_substr(backup[fd], 0, i + 1);
	if (backup[fd][i] != '\n')
		new_backup = 0;
	else
		new_backup = ft_substr(backup[fd], i + 1, ft_strlen(backup[fd] - i));
	free(backup[fd]);
	backup[fd] = new_backup;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	int			len;

	if (fd >= OPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	if (backup[fd] == 0)
		return (0);
	if (ft_strchr(backup[fd], '\n'))
		return (get_line(backup, fd));
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	len = read(fd, buffer, BUFFER_SIZE);
	buffer[len] = '\0';
	if (len < 1)
	{
		free(buffer);
		return (0);
	}
	backup[fd] = ft_strjoin(backup[fd], buffer);
	if (backup[fd] == 0)
		return (0);
	return (get_next_line(fd));
}
