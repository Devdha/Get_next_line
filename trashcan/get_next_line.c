/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:50 by dha               #+#    #+#             */
/*   Updated: 2021/12/08 19:29:22 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*free_init(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (0);
}

static char	*get_line(char **backup, int fd, int len)
{
	char	*line;
	char	*update;
	int		i;

	i = 0;
	if (len == 0)
		return (backup[fd]);
	while (backup[fd][i] != '\n')
		i++;
	line = ft_substr(backup[fd], 0, i + 1);
	update = ft_substr(backup[fd], i + 1, ft_strlen(backup[fd]) - (i + 1));
	free_init(backup + fd);
	backup[fd] = update;
	return (line);
}

static char	*read_buffer(char **backup, int fd)
{
	char	*buffer;
	int		len;

	len = 1;
	while (1)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == 0)
			return (free_init(backup + fd));
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (free_init(&buffer));
		buffer[len] = '\0';
		backup[fd] = ft_strjoinf(backup[fd], buffer);
		if (ft_strchr(backup[fd], '\n') || len == 0)
			return (get_line(backup, fd, len));
	}
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*ret;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	if (backup[fd] == 0)
		return (0);
	ret = read_buffer(backup, fd);
	if (ret == 0)
		return (0);
	return (ret);
}

// #include <stdio.h>
// int main()
// {
// 	int i = 3;
// 	char *a;
// 	while (i--)
// 	{
// 		a = get_next_line(0);
// 		printf("%s\n", a);
// 		free(a);
// 	}
// 	system("leaks a.out");
// }