# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 15:45:33 by youngcho          #+#    #+#              #
#    Updated: 2022/08/31 11:58:04 by youngcho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

INCS_DIR = incs/
INCS_FLAGS = -I $(INCS_DIR) -I $(LIBFT_DIR)incs/

SRCS_DIR = srcs/
OBJS_DIR = objs/

SRCS_NAME = push_swap.c

SRCS_ERROR_DIR = error/
SRCS_ERROR_NAME = error.c
SRCS_NAME += $(addprefix $(SRCS_ERROR_DIR), $(SRCS_ERROR_NAME))

SRCS_PARSING_DIR = parsing/
SRCS_PARSING_NAME = parsing_argument.c \
					parsing_argument_utils.c
SRCS_NAME += $(addprefix $(SRCS_PARSING_DIR), $(SRCS_PARSING_NAME))

SRCS_STACK_DIR = stack/
SRCS_STACK_NAME = init_stack_a_and_b.c \
					stack_cmd_push.c \
					stack_cmd_swap.c \
					stack_cmd_rotate.c \
					stack_cmd_reverse_rotate.c \
					stack_utils.c
SRCS_NAME += $(addprefix $(SRCS_STACK_DIR), $(SRCS_STACK_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

.PHONY: all clean fclean re
all : $(NAME)
clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS_DIR)
fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
re : fclean
	make all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@

$(LIBFT) :
	make all -C $(LIBFT_DIR)
	
$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCS_FLAGS) -c  $< -o $@

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)
	mkdir $(OBJS_DIR)$(SRCS_ERROR_DIR)
	mkdir $(OBJS_DIR)$(SRCS_PARSING_DIR)
	mkdir $(OBJS_DIR)$(SRCS_STACK_DIR)