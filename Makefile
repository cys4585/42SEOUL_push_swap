# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 15:45:33 by youngcho          #+#    #+#              #
#    Updated: 2022/08/29 16:02:02 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
OBJS_DIR = objs/
INCS_DIR = incs/

SRCS_NAME = push_swap.c
OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

.PHONY: all clean fclean re
all : $(NAME)
clean :
	rm -rf $(OBJS_DIR)
fclean : clean
	rm -f $(NAME)
re : fclean
	make all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c  $< -o $@

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)