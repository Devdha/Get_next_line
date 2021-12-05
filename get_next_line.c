/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:50 by dha               #+#    #+#             */
/*   Updated: 2021/12/05 20:41:13 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*ret;
	int			len;
	int			i;

	len = ft_strlen(backup);
	if (len == 0 && backup == 0)
		backup = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
		backup = ft_realloc(backup, len + 1, len + BUFFER_SIZE + 1);
	i = 0;
	while (i < BUFFER_SIZE)
		read(fd, backup + (len + i++), 1);
	i = 0;
	while (*(backup + i))
	{
		
	}
}
