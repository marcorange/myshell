# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlota <acarlota@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 18:30:20 by aoarlota          #+#    #+#              #
#    Updated: 2020/05/24 19:49:22 by acarlota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcmp.c \
ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strequ.c \
ft_strnequ.c ft_strjoin.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
ft_putstr_fd.c  ft_putendl_fd.c ft_putnbr_fd.c ft_atoi.c ft_swap.c ft_strstr.c ft_strnstr.c \
ft_strtrim.c ft_strmapi.c ft_itoa.c ft_strsub.c ft_strsplit.c ft_strndup.c ft_intlen.c ft_return_arr.c ft_freematr.c \
ft_splitit.c get_next_line.c ft_isspace.c ft_words_num.c ft_free_tab.c ft_lstnew.c \
ft_skip_quotes.c ft_arrdup.c

OBJECTS = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o \
ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strcmp.o \
ft_strncmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strequ.o \
ft_strnequ.o ft_strjoin.o ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o \
ft_putstr_fd.o  ft_putendl_fd.o ft_putnbr_fd.o ft_atoi.o ft_swap.o ft_strstr.o ft_strnstr.o \
ft_strtrim.o ft_strmapi.o ft_itoa.o ft_strsub.o ft_strsplit.o ft_strndup.o ft_intlen.o ft_return_arr.o ft_freematr.o \
ft_splitit.o get_next_line.o ft_isspace.o ft_words_num.o ft_free_tab.o ft_lstnew.o \
ft_skip_quotes.o ft_arrdup.o

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc  -c $(CFLAGS) libft.h $(SRC)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
