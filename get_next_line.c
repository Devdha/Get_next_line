/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:50 by dha               #+#    #+#             */
/*   Updated: 2021/12/07 21:49:46 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*exit_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (0);
}

char	*line(char **backup, int fd)
{
	char		*buffer;
	int			i;
	int			len;

	while (1)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == 0)
			return (0);
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (exit_free(&buffer));
		buffer[len] = '\0';
		backup[fd] = ft_strjoinf(backup[fd], buffer);
		if (backup[fd] == 0)
			return (0);
		i = 0;
		while (backup[fd][i])
		{
			if (backup[fd][i] == '\n' || (backup[fd][i] == '\0' && len == 0))
			{
				return (ft_substr(backup[fd], 0, i + 1));
			}
			i++;
		}
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
	ret = line(backup, fd);
	if (ret == 0)
		return (exit_free(backup + fd));
	return (ret);
}


#include <stdio.h>
int main()
{
	int i = 3;
	while (i--)
		printf("%s\n", get_next_line(0));
}