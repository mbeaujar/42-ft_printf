# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeaujar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/18 18:33:42 by mbeaujar          #+#    #+#              #
#    Updated: 2020/09/18 19:09:48 by mbeaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_count_len.c \
       ft_fill_flags.c \
       ft_print_address.c \
       ft_print_char.c \
       ft_print_hex.c \
       ft_print_nbr.c \
       ft_print_percent.c \
       ft_print_put.c \
       ft_print_string.c \
       ft_set_flags.c

OBJS = ${SRCS:.c=.o}

all : $(NAME)

.c.o: 
		$(CC) $(CFLAGS) -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean : 
	rm -f $(OBJS) 

fclean : clean 
	rm -f $(NAME)

re : fclean all 
