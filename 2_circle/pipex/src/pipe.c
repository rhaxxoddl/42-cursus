/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:26:10 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/22 20:42:42 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include <stdio.h>

int	ft_pipe(t_arg *arg, t_cmd_list *cmd_list)
{
	pid_t	pid;

	if (pipe(arg->fds[cmd_list->cmd_idx]) == -1)
		p_a_error(arg);
	pid = fork();
	if (pid == -1)
		p_a_error(arg);
	else if (pid == 0)
	{
		connect_pipe(cmd_list->cmd_idx, arg);
		if (execve(cmd_list->cmd_path,
				cmd_list->cmd_with_option, arg->envp) == -1)
			p_a_error(arg);
	}
	if (pid)
	{
		dup2(arg->fds[cmd_list->cmd_idx][R], STDIN_FILENO);
		close(arg->fds[cmd_list->cmd_idx][W]);
		close(arg->fds[cmd_list->cmd_idx][R]);
		waitpid(pid, &(arg->status), 0);
	}
	return (0);
}

void	connect_pipe(int cmd_idx, t_arg *arg)
{
	if (cmd_idx == 0)
	{
		if (redir_in(arg->infile) == -1)
			p_a_error(arg);
	}
	if (cmd_idx == arg->cmd_count - 1)
	{
		if (redir_out(arg->outfile) == -1)
			p_a_error(arg);
	}
	else
	{
		if (dup2(arg->fds[cmd_idx][W], STDOUT_FILENO) == -1)
			p_a_error(arg);
		close(arg->fds[cmd_idx][W]);
		close(arg->fds[cmd_idx][R]);
	}
}
