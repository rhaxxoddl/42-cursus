/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:55:12 by sanjeon           #+#    #+#             */
/*   Updated: 2021/01/02 17:35:05 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char		*s;
	size_t			n;

	s = src;
	n = size;
	if (!dest && !src)
		return (0);
	while (*s && --n - 1 < size)
		*dest++ = *s++;
	if (size)
		*dest = '\0';
	return (ft_strlen(src));
}
