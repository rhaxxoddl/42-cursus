/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 05:04:20 by sanjeon           #+#    #+#             */
/*   Updated: 2021/04/24 17:40:47 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		find_new_line(int fd, char **line, char *buf, char **backup);
char	*add_buf(char *buf);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *d, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		out_line(char *buf, char *nl, char **backup, char **line);
size_t	ft_strlen(char	*s);

#endif
