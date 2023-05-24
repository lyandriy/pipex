/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:33:37 by lyandriy          #+#    #+#             */
/*   Updated: 2023/05/17 18:33:56 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_str *all, char **argv)
{
	open_file_one(argv, all);
	all->i = 0;
	if (pipe(all->fd[FD_READ]) == -1)
		ft_error_free(all);
	close(all->fd[FD_READ][WRITING]);
	while (all->i < all->all_commands)
	{
		open_pipe(all);
		find_command_path(argv[all->pos_command], all);
		ft_child(all);
		if (all->i != (all->all_commands - 1))
		{
			if (dup2(all->fd[PIPE][READING], all->fd[FD_READ][READING]) == -1)
			{
				error_close_fd(all);
				ft_error_free(all);
			}
		}
		close_fd(all);
		all->i++;
		all->pos_command++;
		free_array(all->path_command);
	}
	ft_wait(all);
	free_array(all->separate_path);
}

void	find_command_path(char *com, t_str *all)
{
	char	*path;
	char	*command;
	int		go;

	go = 0;
	all->path_command = ft_split(com, 32);
	if (!all->path_command[0])
		ft_error_exec(all);
	command = ft_strdup(all->path_command[0]);
	path = NULL;
	while (access(all->path_command[0], F_OK) == -1 && all->separate_path[go])
	{
		join_com(all, command, path, go);
		go++;
	}
	if (access(all->path_command[0], F_OK) == -1)
	{
		error_close_fd(all);
		ft_error_free(all);
	}
	free(command);
}

void	ft_child(t_str *all)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (all->i == 0)
			first_command(all);
		if (all->i == (all->all_commands - 1))
			last_command(all);
		if (all->i != 0 && all->i != (all->all_commands - 1))
			command_process(all);
		if (execve(all->path_command[0], all->path_command, NULL) == -1)
		{
			ft_error_exec(all);
			ft_printf("upss: %s\n", strerror(ENODEV));
			exit(1);
		}
	}
}
