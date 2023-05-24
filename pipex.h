/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:57:45 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 17:01:58 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_str
{
	char	**path_command;
	char	**separate_path;
	int		all_commands;
	int		pos_command;
	int		all_pipe;
	int		fd[2][2];
	int		fd_in[2];
	int		i;
}		t_str;

# define EINVAL	22 /* Invalid argument */
# define EACCES	13	/* Permission denied */
# define ENODEV	19	/* Operation not supported by device */
# define READING	0
# define WRITING	1
# define FD_READ	0
# define PIPE	1

int		main(int argc, char **argv, char **env);
t_str	pos_commands(int argc, char **argv);
void	check_input(int argc, char **argv, t_str *all);
void	check_access(char *argv, t_str *all);
void	check_input_here_doc(int argc, char **argv, t_str *all);
void	heredoc_function(char *limiter, t_str *all);
int		strcmp(const char *s1, const char *s2);
void	ft_path(char **env, t_str *all);
char	*find_path(char **env, t_str *all);
void	pipex(t_str *all, char **argv);
void	open_file_one(char **argv, t_str *all);
void	open_pipe(t_str *all);
void	find_command_path(char *com, t_str *all);
void	join_com(t_str *all, char *com, char *path, int go);
void	ft_child(t_str *all);
void	first_command(t_str *all);
void	last_command(t_str *all);
void	command_process(t_str *all);
void	close_fd(t_str *all);
void	free_array(char **str);
void	ft_error(void);
void	ft_error_free(t_str *all);
void	error_close_fd(t_str *all);
void	ft_error_exec(t_str *all);
void	ft_error_fd(int fd_error, int fd_to_close);
void	ft_wait(t_str *all);

#endif