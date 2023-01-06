/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:08 by hadufer           #+#    #+#             */
/*   Updated: 2023/01/06 11:03:45 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

# define BUFFER_SIZE	1

size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_strchr(char *s, int c);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strndup(char	*str, size_t n);
char	*get_next_line(int fd);
void	*gnl_ft_calloc(size_t nmemb, size_t size);
#endif
