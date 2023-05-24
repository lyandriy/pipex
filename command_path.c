/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:02:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 12:28:12 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_path(char **env, t_str *all)
{
	int		i;
	char	*path;

	i = 0;
	path = find_path(env, all);
	all->separate_path = ft_split(&path[5], ':');
}

char	*find_path(char **env, t_str *all)
{
	int		count;
	char	*path;

	count = 0;
	path = NULL;
	while (path == NULL && env[count] != NULL)
	{
		path = ft_strnstr(env[count], "PATH=", ft_strlen(env[count]));
		count++;
	}
	if (env[count] == NULL)
	{
		ft_printf("upss: The command could not be located ");
		ft_printf("because the PATH environment variable does not exist\n");
		close(all->fd_in[WRITING]);
		close(all->fd_in[READING]);
		exit(1);
	}
	return (path);
}
