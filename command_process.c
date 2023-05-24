/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:36:26 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 17:09:36 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_str *all)
{
	if (dup2(all->fd_in[READING], 0) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	close(all->fd_in[READING]);
	if (dup2(all->fd[PIPE][WRITING], 1) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	close(all->fd[PIPE][WRITING]);
	close(all->fd[PIPE][READING]);
	close(all->fd[FD_READ][READING]);
	close(all->fd_in[WRITING]);
}

void	last_command(t_str *all)
{
	if (dup2(all->fd[FD_READ][READING], 0) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	close(all->fd[FD_READ][READING]);
	if (dup2(all->fd_in[WRITING], 1) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	close(all->fd_in[WRITING]);
}

void	command_process(t_str *all)
{
	if (dup2(all->fd[FD_READ][READING], 0) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	close(all->fd[FD_READ][READING]);
	if (dup2(all->fd[PIPE][WRITING], 1) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	close(all->fd[PIPE][WRITING]);
	close(all->fd[PIPE][READING]);
	close(all->fd_in[WRITING]);
}
