/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:17:27 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 17:21:32 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("upss");
	exit(1);
}

void	ft_error_free(t_str *all)
{
	if (all->path_command)
		free_array(all->path_command);
	if (all->separate_path)
		free_array(all->separate_path);
	perror("upss");
	exit(1);
}

void	ft_error_exec(t_str *all)
{
	if (all->path_command)
	{
		error_close_fd(all);
		free_array(all->path_command);
	}
	if (all->separate_path)
	{
		error_close_fd(all);
		free_array(all->separate_path);
	}
	exit(1);
}

void	error_close_fd(t_str *all)
{
	if (all->i == 0)
	{
		close(all->fd[FD_READ][READING]);
		close(all->fd_in[READING]);
		close(all->fd_in[WRITING]);
		if (all->pos_command == 3)
			unlink(".here_doc");
	}
	if (all->i == (all->all_commands - 1))
	{
		close(all->fd[FD_READ][READING]);
		close(all->fd_in[WRITING]);
	}
	if (all->i != 0 && all->i != (all->all_commands - 1))
	{
		close(all->fd[FD_READ][READING]);
		close(all->fd_in[WRITING]);
		close(all->fd[PIPE][READING]);
		close(all->fd[PIPE][WRITING]);
	}
}

void	ft_error_fd(int fd_error, int fd_to_close)
{
	if (fd_error < 0)
	{
		if (fd_to_close > 0)
			close(fd_to_close);
		ft_error();
	}
}
