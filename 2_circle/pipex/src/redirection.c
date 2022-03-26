/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:59:13 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/22 20:15:57 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include <fcntl.h>

int	redir_in(const char *filename)
{
	int	fd;

	if (access(filename, R_OK) == -1)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	return (1);
}

int	redir_out(const char *filename)
{
	int	fd;

	fd = open(filename,
			O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	printf("hi\n");
	return (1);
}

int	redir_app(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND);
	if (fd < 0)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	return (1);
}
