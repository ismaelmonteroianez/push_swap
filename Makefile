# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 11:38:10 by ismonter          #+#    #+#              #
#    Updated: 2026/03/10 19:21:29 by ismonter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCE = \
	src/push_swap.c \
	src/ft_parser.c \
	utils/ft_strdup.c \
	utils/ft_strlcpy.c \
	utils/ft_split.c \
	utils/ft_isdigit.c \
	src/ft_matrix_tools.c \
	utils/ft_calloc.c \
	src/ft_fill_list.c \
	utils/ft_lst_second_last.c \
	utils/ft_lstadd_back.c \
	utils/ft_lstadd_front.c \
	utils/ft_lstclear.c \
	utils/ft_lstlast.c \
	utils/ft_lstnew.c \
	src/ft_parser_tools.c \
	utils/ft_atol.c \
	utils/ft_strcmp.c \
	src/ft_sort.c \
	utils/ft_lstiter.c \
	utils/ft_lstsize.c \
	src/ft_flags.c \
	src/ft_simple.c \
	src/ft_medium.c \
	src/ft_quicksort.c \
	src/ft_push.c \
	src/ft_reverse_rotate.c \
	src/ft_swap.c \
	src/ft_rotate.c \
	src/ft_sort_tools.c \
	src/ft_bench.c \
	utils/ft_printnbr.c \
	src/ft_adaptive.c \
	src/ft_complex.c \
	src/ft_tiny_sort.c

OBJS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME).a $(OBJS)
	cc $(NAME).a -o $(NAME)

%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME).a

re: fclean all