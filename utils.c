/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:43:12 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 18:46:21 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_str	pos_commands(int argc, char **argv)
{
	t_str	all;

	if (ft_strncmp(argv[1], "here_doc", 9) != 0)
	{
		all.all_commands = argc - 3;
		all.pos_command = 2;
	}
	else
	{
		if (argc < 6)
		{
			ft_printf("upss: %s\n", strerror(EINVAL));
			exit(1);
		}
		all.all_commands = argc - 4;
		all.pos_command = 3;
	}
	all.all_pipe = all.all_commands - 1;
	return (all);
}

void	free_array(char **str)
{
	int	count;

	count = 0;
	if (str)
	{
		while (str[count])
		{
			free(str[count]);
			count++;
		}
	}
	free(str);
}

void	join_com(t_str *all, char *com, char *path, int go)
{
	free(all->path_command[0]);
	path = ft_strjoin(all->separate_path[go], "/");
	if (!path)
		free(path);
	all->path_command[0] = ft_strjoin(path, com);
	free(path);
}

void	ft_wait(t_str *all)
{
	int	j;

	j = 0;
	while (j++ < all->all_commands)
		wait(0);
}
