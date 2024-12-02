
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 18:55:09 by edubois-          #+#    #+#              #
#    Updated: 2024/11/29 22:12:07 by edubois-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= push_swap

DIR_LIB 	=  lib
PRINTF_DIR 	=  $(DIR_LIB)/printf
PRINTF_LIB 	:= $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR 	=  $(DIR_LIB)/libft
LIBFT_LIB 	:= $(LIBFT_DIR)/libft.a

SRCS =  srcs/main.c\
		srcs/get_stack.c \
		srcs/clean_exit.c\
		srcs/parse_arg.c\
		srcs/start_sort.c\
		srcs/function_a/ft_function_a.c\
		srcs/function_a/ft_function_b.c\
		srcs/function_a/ft_function_ba.c\
		srcs/function_a/ft_function_shared.c\
		srcs/algo/ft_turkish.c\
		srcs/ft_quicksort/quicksort.c

OBJS = $(SRCS:.c=.o)

CC := cc
FLAGS := -Wall -Wextra -Werror -g

.SILENT:

all: $(NAME)

$(NAME): animate $(PRINTF_LIB) $(OBJS) $(LIBFT_LIB)
	echo "Compilation de $(NAME)..."
	$(CC) $(FLAGS) -o $@ $(OBJS) $(PRINTF_LIB) $(LIBFT_LIB)

animate:
	echo -n "Compilation en cours "
	for i in 1 2 3 4 5; do \
		sleep 0.1; echo -n "."; \
	done
	echo ""

$(PRINTF_LIB):
	echo "Compilation de la bibliothèque printf..."
	make -s -C $(PRINTF_DIR)

$(LIBFT_LIB):
	echo "Compilation de la bibliothèque libft..."
	make -s -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	echo "Nettoyage des fichiers objets..."
	make clean -s -C $(PRINTF_DIR)
	make clean -s -C $(LIBFT_DIR)	
	rm -f $(OBJS)

fclean: clean
	echo "Suppression des exécutables..."
	make fclean -s -C $(PRINTF_DIR)
	make fclean -s -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re animate
