# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 17:21:35 by lyandriy          #+#    #+#              #
#    Updated: 2023/04/06 18:49:53 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  check_input.c\
	  pipex.c\
	  command_path.c\
	  utils.c\
	  command_process.c\
	  treatment_fd.c\
	  error.c\

GNL = get_next_line/get_next_line.a
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
OBJ = $(SRC:.c=.o)

NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(GNL):
	@make -C get_next_line
$(LIBFT):
	@make -C libft
$(PRINTF):
	@make -C ft_printf

$(NAME) : $(OBJ) $(GNL) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C get_next_line
	@make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C get_next_line
	@make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re