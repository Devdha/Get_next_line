/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:49 by dha               #+#    #+#             */
/*   Updated: 2021/12/08 19:27:55 by dha              ###   ########seoul.kr  */
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

char	*ft_strjoinf(char *s1, char *s2)
{
	size_t	i;
	size_t	s_i;
	char	*str;

	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	i = 0;
	s_i = 0;
	while (i < ft_strlen(s1))
		str[i++] = s1[s_i++];
	while (i < ft_strlen(s1) + ft_strlen(s2))
		str[i++] = s2[s_i++ - ft_strlen(s1)];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = ft_strlen(s1);
	ret = (char *) malloc(sizeof(char) * len + 1);
	if (ret == 0)
		return (0);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;

	s_len = ft_strlen(s);
	if (s_len <= start || len == 0 || s_len == 0)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
