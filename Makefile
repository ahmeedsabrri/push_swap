# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabri <asabri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 04:53:49 by asabri            #+#    #+#              #
#    Updated: 2023/04/11 08:24:26 by asabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = Mandatory/ft_strlen.c Mandatory/ft_printf_utils.c Mandatory/ft_printf.c Mandatory/ft_printf_d.c Mandatory/ft_strjoin.c Mandatory/ft_split.c \
	Mandatory/ft_atoi.c Mandatory/ft_substr.c Mandatory/utitls.c Mandatory/instructions1.c Mandatory/instructions2.c Mandatory/instructions3.c Mandatory/instructions4.c Mandatory/sort_algo1.c Mandatory/sor_algo2.c Mandatory/sort_algo3.c
OBJS = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)
		@echo "*****Compiling OBJS files*****"
		@echo "*****Compiling OBJS files*****"

%.o : %c Mandatory/push_swap.h
		$(CC) $(CFLAGS) -o $@ -c $<

push_swap : $(OBJS) Mandatory/push_swap.o 
		$(CC) $(FLAGS) -o push_swap $(OBJS) Mandatory/push_swap.o

clean :
	$(RM) $(OBJS) Mandatory/push_swap.o
fclean : clean
		$(RM) $(NAME)
		@echo "*****Deleting OBJS files*****"
		@echo "*****Deleting Output files*****"

re : fclean all
