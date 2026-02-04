# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 11:29:26 by tzammar           #+#    #+#              #
#    Updated: 2026/02/04 19:47:58 by tzammar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs
RM      := rm -f

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
GNL_DIR = ./gnl

INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)
LFLAGS = -L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(GNL_DIR)
LIBS = -l:libft.a -l:libftprintf.a -l:get_next_line.a

SRCS	:= ./src/push_swap.c \
			./src/stack.c \
			./src/error_handiling.c \
			./src/sort.c \
			./src/pop.c \
			./src/swap.c \
			./src/push.c \
			./src/rotate.c \
			./src/rrotate.c \
			./src/radix_sort.c \
			./src/parse.c
OBJS	:= $(SRCS:.c=.o)
NAME	:= push_swap

BONUS_SRCS	:= ./src/checker_bonus.c\
			./src/stack.c \
			./src/error_handiling.c \
			./src/sort.c \
			./src/pop.c \
			./src/swap.c \
			./src/push.c \
			./src/rotate.c \
			./src/rrotate.c \
			./src/radix_sort.c \
			./src/parse.c
BONUS_OBJS	:= $(BONUS_SRCS:.c=.o)
BONUS_NAME	:= checker

all: libft printf gnl $(NAME)

bonus: libft printf gnl $(BONUS_NAME)

libft:
	@echo "--- Entering libft directory to build..."
	$(MAKE) -C $(LIBFT_DIR)
	@echo "--- libft build complete."

printf:
	@echo "--- Entering printf directory to build..."
	$(MAKE) -C $(PRINTF_DIR)
	@echo "--- printf build complete."

gnl:
	@echo "--- Entering gnl directory to build..."
	$(MAKE) -C $(GNL_DIR)
	@echo "--- gnl build complete."

$(NAME): $(OBJS)
	@echo "--- Linking executable $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "--- Executable $(NAME) successfully created."

$(BONUS_NAME): $(BONUS_OBJS)
	@echo "--- Linking executable $(BONUS_NAME)..."
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LFLAGS) $(INCLUDES) $(LIBS) -o $(BONUS_NAME)
	@echo "--- Executable $(BONUS_NAME) successfully created."

%.o: %.c
	@echo "--- Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "--- Removing object files..."
	$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "--- Removing object files from sub-projects..."
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(GNL_DIR)

fclean: clean
	@echo "--- Removing executable $(NAME)..."
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "--- Calling fclean in sub-projects..."
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR)

re: fclean all

re_bonus: fclean all bonus

.PHONY: all bonus clean fclean re re_bonus libft printf gnl
