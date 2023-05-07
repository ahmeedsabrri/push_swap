# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 04:53:49 by asabri            #+#    #+#              #
#    Updated: 2023/05/07 21:24:10 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = Mandatory/ft_strlen.c Mandatory/ft_strjoin.c Mandatory/ft_split.c \
	Mandatory/ft_atoi.c Mandatory/ft_substr.c Mandatory/utitls.c Mandatory/instructions1.c Mandatory/instructions2.c Mandatory/instructions3.c Mandatory/instructions4.c \
	Mandatory/sort_algo1.c Mandatory/sor_algo2.c Mandatory/sort_algo3.c Mandatory/push_swap_utils.c Mandatory/ft_error.c Mandatory/sort_algo3_utils.c Mandatory/sort_utils.c \
	Mandatory/libftmalloc/ft_malloc.c Mandatory/libftmalloc/utils_malloc.c Mandatory/ft_parsing.c

SRCB = Mandatory/ft_strlen.c Mandatory/ft_strjoin.c Mandatory/ft_split.c \
	Mandatory/ft_atoi.c Mandatory/ft_substr.c Mandatory/utitls.c Mandatory/instructions1.c Mandatory/instructions2.c Mandatory/instructions3.c Mandatory/instructions4.c \
	Mandatory/sort_algo1.c Mandatory/sor_algo2.c Mandatory/sort_algo3.c Mandatory/push_swap_utils.c Mandatory/ft_error.c Mandatory/sort_algo3_utils.c Mandatory/sort_utils.c \
	Mandatory/libftmalloc/ft_malloc.c Mandatory/libftmalloc/utils_malloc.c Mandatory/ft_parsing.c bonus/ft_strcmp.c bonus/GNL/get_next_line.c bonus/GNL/get_next_line_utils.c 

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf

all : $(NAME)
		@echo "*****Compiling OBJS files*****"
		@echo "*****Compiling OBJS files*****"

%.o : %c Mandatory/push_swap.h 
		$(CC) $(CFLAGS) -o $@ -c $<

push_swap : $(OBJS) Mandatory/push_swap.o 
		$(CC) $(FLAGS) -o push_swap $(OBJS) Mandatory/push_swap.o
checker : $(OBJSB) bonus/checker.o
		$(CC) $(FLAGS) -o checker $(OBJSB) bonus/checker.o
clean :
	$(RM) $(OBJS) $(OBJSB) Mandatory/push_swap.o bonus/checker.o
fclean : clean
		$(RM) $(NAME)
		@echo "*****Deleting OBJS files*****"
		@echo "*****Deleting Output files*****"
bonus : checker
re : fclean all
