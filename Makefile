# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/05 15:43:48 by acarlota          #+#    #+#              #
#    Updated: 2020/04/07 15:34:33 by acarlota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/*.c

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

all : $(NAME)

$(NAME):
	@make -C libft re
	@gcc -Wall -Wextra -Werror $(SRC) $(LIBFT) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all