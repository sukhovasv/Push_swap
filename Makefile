# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 15:40:53 by ssukhova          #+#    #+#              #
#    Updated: 2024/04/24 14:21:57 by ssukhova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
DEBUG_FLAGS	:= -g
INC_DIR		:= ./lib/libft/include ./include
BUILD_DIR	=  out
BIN_DIR		=  .
OBJ_DIR		=  $(BUILD_DIR)/obj
SRC_DIR		=  src
LIBFT_PATH	=  ./lib/libft
LIBFT		=  $(LIBFT_PATH)/libft.a
INCLUDES	:= -I. $(INC_DIR:%=-I%)
CFLAGS		+= $(INCLUDES)
LINK_FLAGS	:= -L $(LIBFT_PATH) -lft
RM 			:= rm -rf

ifeq ($(DEBUG),1)
CFLAGS += $(DEBUG_FLAGS)
endif

SRCS = src/get_index.c src/push.c src/rotate.c src/swap.c src/stack_init.c \
       src/input_validation.c src/reverse_rotate.c src/free.c src/utils.c \
       src/sort_stack.c src/main.c src/tiny_sort.c src/struct_init.c \
	   src/utils2.c src/sort_both_stacks.c src/init.c \
	   src/input_validation_one_arg.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^ $(LINK_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
