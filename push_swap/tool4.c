/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:57:01 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 21:57:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		    ft_atol(const char *nptr)
    {
        int 		i;
        int	    	sign;
        char	    *str;
        long long   num;

	i = 0;
	str = (char*)nptr;
	num = 0;
	sign = -1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		num = num * 10 - str[i++] + '0';
	return (sign * num);
}