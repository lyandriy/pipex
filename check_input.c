/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:28:14 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 16:24:29 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_input(int argc, char **argv, t_str *all)
{
	if (ft_strncmp(argv[1], "here_doc", 9) != 0)
	{
		if (access(argv[1], F_OK) == -1)
			ft_error();
		check_access(argv[argc - 1], all);
		if (access(argv[argc - 1], F_OK) != -1)
		{
			all->fd_in[1] = open(argv[argc - 1], O_TRUNC | O_WRONLY);
			ft_error_fd(all->fd_in[1], 0);
		}
		if (access(argv[1], R_OK) == -1 || access(argv[argc - 1], W_OK) == -1)
			ft_error();
		if (access(argv[1], R_OK) != -1)
		{
			all->fd_in[0] = open(argv[1], O_RDONLY);
			ft_error_fd(all->fd_in[0], all->fd_in[1]);
		}
	}
	else
		check_input_here_doc(argc, argv, all);
}

void	check_input_here_doc(int argc, char **argv, t_str *all)
{
	check_access(argv[argc - 1], all);
	if (access(argv[argc - 1], F_OK) != -1)
	{
		all->fd_in[1] = open(argv[argc - 1], O_WRONLY | O_APPEND);
		ft_error_fd(all->fd_in[0], all->fd_in[1]);
	}
	if (access(argv[argc - 1], W_OK) == -1)
		ft_error();
	heredoc_function(argv[2], all);
}

void	check_access(char *argv, t_str *all)
{
	if (access(argv, F_OK) == -1)
	{
		all->fd_in[1] = open(argv, O_WRONLY | O_CREAT, 0644);
		ft_error_fd(all->fd_in[1], 0);
	}
}

void	heredoc_function(char *limiter, t_str *all)
{
	const char	*file_name = ".here_doc";
	char		*line_heredoc;

	if (access(file_name, F_OK) == 0)
		unlink(file_name);
	all->fd_in[0] = open(file_name, O_CREAT | O_RDWR, 0644);
	ft_error_fd(all->fd_in[0], all->fd_in[1]);
	while (all->fd_in[0])
	{
		write (1, "heredoc> ", 9);
		line_heredoc = get_next_line(0);
		if (line_heredoc == NULL || strcmp(line_heredoc, limiter) == 0)
		{
			free(line_heredoc);
			return ;
		}
		write(all->fd_in[0], line_heredoc, ft_strlen(line_heredoc));
		free(line_heredoc);
	}
}

int	strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if ((ft_strlen(s1) - 1) == ft_strlen(s2))
	{
		while (s1[i] != '\n')
		{
			if (s1[i] != s2[i])
				return (-1);
			i++;
		}
		return (0);
	}
	return (-1);
}
