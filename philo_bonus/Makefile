# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmyrl <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 23:30:21 by dmyrl             #+#    #+#              #
#    Updated: 2022/01/29 23:30:38 by dmyrl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
HEAD	= philo_bonus.h
CC		= clang
CFLAGS	= -Wall -Wextra -Werror
SRC		= main_bonus.c support_bonus.c init_bonus.c solution_bonus.c
OBJ = ${SRC:.c=.o}

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
