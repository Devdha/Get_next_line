/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:49 by dha               #+#    #+#             */
/*   Updated: 2021/12/05 20:39:56 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*cp;

	if (s == 0)
		return (0);
	cp = s;
	while (*cp)
		cp++;
	return (cp - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	while (index < src_len && index + 1 < dstsize)
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize > 0)
		dst[index] = '\0';
	return (src_len);
}

char	*ft_realloc(char *ptr, size_t sz, size_t new_sz)
{
	size_t	i;
	void	*new;

	i = 0;
	new = malloc(sizeof(char) * new_sz);
	while (i < sz && i < new_sz)
	{
		new[i] = ptr[i];
		i++;
	}
	new[i] = '\0';
	free(ptr);
	return (new);
}
