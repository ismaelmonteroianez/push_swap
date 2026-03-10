# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 11:38:10 by ismonter          #+#    #+#              #
#    Updated: 2026/03/10 18:38:16 by ismonter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCE = \
	push_swap.c \
	ft_parser.c \
	ft_strdup.c \
	ft_strlcpy.c \
	ft_split.c \
	ft_isdigit.c \
	ft_matrix_tools.c \
	ft_calloc.c \
	ft_fill_list.c \
	ft_lst_second_last.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_parser_tools.c \
	ft_atol.c \
	ft_strcmp.c \
	ft_sort.c \
	ft_lstiter.c \
	ft_lstsize.c \
	ft_flags.c \
	ft_simple.c \
	ft_medium.c \
	ft_quicksort.c \
	ft_push.c \
	ft_reverse_rotate.c \
	ft_swap.c \
	ft_rotate.c \
	ft_sort_tools.c \
	ft_bench.c \
	ft_printnbr.c \
	ft_adaptive.c \
	ft_complex.c \
	ft_tiny_sort.c

OBJS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
	rm -f $(OBJS)
	rm -f $(NAME).a

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