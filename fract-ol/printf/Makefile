# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coraline <coraline@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 14:00:54 by coraline          #+#    #+#              #
#    Updated: 2025/03/11 19:32:43 by coraline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_print_char.c ft_print_hexa.c ft_putnbr.c
OBJS = $(SRCS:.c=.o)
MAIN = main.c
EXEC = test_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main.o

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all

test: $(NAME) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(EXEC)
	./$(EXEC)
