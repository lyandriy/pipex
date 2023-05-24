/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:09:27 by lyandriy          #+#    #+#             */
/*   Updated: 2023/04/06 17:14:25 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_str	all;

	if (argc < 5)
	{
		ft_printf("upss: %s\n", strerror(EINVAL));
		exit(1);
	}
	all = pos_commands(argc, argv);
	check_input(argc, argv, &all);
	ft_path(env, &all);
	pipex(&all, argv);
	return (0);
}
