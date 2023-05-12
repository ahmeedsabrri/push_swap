# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 04:53:49 by asabri            #+#    #+#              #
#    Updated: 2023/05/11 20:34:01 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

SRC = Mandatory/ft_strlen.c Mandatory/ft_strjoin.c Mandatory/ft_split.c  Mandatory/push_swap.c \
	Mandatory/ft_atoi.c Mandatory/ft_substr.c Mandatory/utitls.c Mandatory/instructions1.c Mandatory/instructions2.c Mandatory/instructions3.c Mandatory/instructions4.c \
	Mandatory/sort_algo1.c Mandatory/sor_algo2.c Mandatory/sort_algo3.c Mandatory/push_swap_utils.c Mandatory/ft_error.c Mandatory/sort_algo3_utils.c Mandatory/sort_utils.c \
	Mandatory/libftmalloc/ft_malloc.c Mandatory/libftmalloc/utils_malloc.c Mandatory/ft_parsing.c

SRCB = Mandatory/ft_strlen.c Mandatory/ft_strjoin.c Mandatory/ft_split.c bonus/checker.c \
	Mandatory/ft_atoi.c Mandatory/ft_substr.c Mandatory/utitls.c Mandatory/instructions1.c Mandatory/instructions2.c Mandatory/instructions3.c Mandatory/instructions4.c \
	Mandatory/sort_algo1.c Mandatory/sor_algo2.c Mandatory/sort_algo3.c Mandatory/push_swap_utils.c Mandatory/ft_error.c Mandatory/sort_algo3_utils.c Mandatory/sort_utils.c \
	Mandatory/libftmalloc/ft_malloc.c Mandatory/libftmalloc/utils_malloc.c Mandatory/ft_parsing.c bonus/ft_strcmp.c bonus/get_next_line.c bonus/get_next_line_utils.c 


CC = cc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf
HEADER_M =  Mandatory/push_swap.h 
HEADER_B =  bonus/checker.h 

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

all : $(NAME)

Mandatory/%.o : Mandatory/%.c $(HEADER_M)
		$(CC) $(FLAGS) -o $@ -c $<

bonus/%.o : bonus/%.c $(HEADER_B)
		$(CC) $(FLAGS) -o $@ -c $<

$(NAME) : $(OBJS) $(HEADER_M)
		$(CC) $(FLAGS) $(OBJS)  -o $@ 
$(CHECKER) : $(OBJSB) $(HEADER_B)
		$(CC) $(FLAGS) $(OBJSB)  -o $@ 
clean :
	$(RM) $(OBJS) $(OBJSB) 
fclean : clean
		$(RM) $(NAME) $(CHECKER)
bonus : $(CHECKER)
re : fclean all
