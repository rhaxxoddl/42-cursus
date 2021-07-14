/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:25:20 by sanjeon           #+#    #+#             */
/*   Updated: 2020/12/26 14:16:04 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *d, int c)
{
	while (*d || *d == (char)c)
	{
		if (*d == (char)c)
			return ((char*)d);
		d++;
	}
	return (0);
}
