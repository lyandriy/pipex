/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatment_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:43:32 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 12:30:16 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file_one(char **argv, t_str *all)
{
	if (ft_strncmp(argv[1], "here_doc", 9) != 0)
	{
		close (all->fd_in[0]);
		all->fd_in[0] = open(argv[1], O_RDWR);
	}
	else
	{
		close (all->fd_in[0]);
		all->fd_in[0] = open(".here_doc", O_RDWR);
	}
	if (all->fd_in[0] == -1)
	{
		close(all->fd_in[WRITING]);
		free_array(all->separate_path);
		perror("upss");
	}
}

void	open_pipe(t_str *all)
{
	if (all->i < (all->all_commands - 1))
	{
		if (pipe(all->fd[1]) == -1)
		{
			error_close_fd(all);
			ft_error_free(all);
		}
	}
}

void	close_fd(t_str *all)
{
	if (all->i == 0)
	{
		close(all->fd[PIPE][WRITING]);
		close(all->fd[PIPE][READING]);
		close(all->fd_in[READING]);
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
		close(all->fd[PIPE][READING]);
		close(all->fd[PIPE][WRITING]);
	}
}
