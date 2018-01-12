# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcosson <vcosson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/06 14:23:25 by shedelin          #+#    #+#              #
#    Updated: 2014/04/30 16:53:36 by shedelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIRLIB = libft/

DIRSRC = srcs/

DIRH = includes/

SRC = main.c \
      ft_sl_dokey.c \
      ft_sl_dolst.c \
      ft_sl_error.c \
      ft_sl_lst.c \
      ft_sl_move.c \
      ft_sl_out.c \
      ft_sl_put.c \
      ft_sl_signal.c \
      ft_sl_search.c \
      ft_sl_singleton.c

OBJ = $(SRC:.c=.o)

all: init $(NAME)

init:
	@echo "\033[0;32m 					$(NAME) PROJECT\033[0m"

$(NAME): $(OBJ)
	@make -s -C $(DIRLIB)
	@$(CC) $(FLAGS) -o $(NAME) $^ -I$(DIRLIB) -I$(DIRH) -L$(DIRLIB) -lft -ltermcap
	@echo "\033[1;32m ft_select: OK\033[0m"

%.o: $(DIRSRC)%.c
	@echo -n .
	@$(CC) $(FLAGS) -o $@ -c $< -I$(DIRLIB)$(DIRH) -I$(DIRH)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(DIRLIB)
	@echo "\033[4;32mDeleted:\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@make -C $(DIRLIB) $@
	@rm -f $(NAME)
	@echo "\033[4;32mDeleted:\033[0;33m $(NAME)\033[0m"

re: fclean all

exec: all
	rm -f log.txt
	./ft_select * * * * * * * * * *
	cat log.txt | less

.PHONY: all clean fclean re
