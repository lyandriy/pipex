/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:25:35 by lyandriy          #+#    #+#             */
/*   Updated: 2023/03/31 21:18:55 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char arg)
{
	write(2, &arg, sizeof(char));
	return (1);
}

int	ft_print_s(char *arg)
{
	int	i;

	i = 0;
	if (arg == NULL)
	{
		write(2, "(null)", 6);
		i = 6;
	}
	else
	{
		while (arg[i] != '\0')
		{
			write(2, &arg[i], sizeof(char));
			i++;
		}
	}
	return (i);
}

int	ft_print_p(void *arg)
{
	int	count_write;

	count_write = write(2, "0x", 2);
	count_write += ft_puthex((size_t) arg, "0123456789abcdef");
	return (count_write);
}

int	ft_print_d_i(int arg)
{
	int	count_write;
	int	j;

	j = arg;
	count_write = 0;
	if (arg < 0)
	{
		write(2, "-", 1);
		arg *= -1;
		count_write++;
	}
	count_write += ft_putnbr(arg);
	return (count_write);
}

int	ft_print_u(unsigned int arg)
{
	int			count_write;
	long int	j;

	count_write = 0;
	j = arg;
	count_write += ft_putnbr(arg);
	return (count_write);
}
