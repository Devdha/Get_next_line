/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:39:51 by dha               #+#    #+#             */
/*   Updated: 2021/12/07 21:16:04 by dha              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoinf(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif