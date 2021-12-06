/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:50 by dha               #+#    #+#             */
/*   Updated: 2021/12/06 21:26:52 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*save;
	char		*tmp;
	int			i;

	if (fd > OPEN_MAX || BUFFER_SIZE < 1 || 0)
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	if (backup[fd] == 0)
		return (0);
	while (1)
	{
		i = 0;
		save = 
		if ((read(fd, save, BUFFER_SIZE)) < 1)
			return (0);
		save[i] = '\0';
		backup[fd] = ft_strjoinf(backup[fd], save);
		i = 0;
		while (backup[fd][i] != '\n' || backup[fd][i] != '\0')
			i++;
		if (backup[fd][i] == '\n' || backup[fd][i] == -1)
			return backup[fd]; // 수정
		
	}
}
