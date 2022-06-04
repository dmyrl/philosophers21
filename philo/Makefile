# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 19:38:32 by dmyrl             #+#    #+#              #
#    Updated: 2022/01/29 19:38:34 by dmyrl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
HEAD	= philo.h
CC		= clang
CFLAGS 	= -Wall -Wextra -Werror -pthread
SRC		= main.c init.c solution.c support.c
OBJ		= ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c $(HEAD)
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
