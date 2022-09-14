# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:12:29 by rjeong            #+#    #+#              #
#    Updated: 2022/09/06 15:12:32 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS_NAME := checker
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
RM := rm -f

PUSH_SWAP_SRCS := \
	push_swap.c \

PUSH_SWAP_SRCS_BONUS := \

PUSH_SWAP_OBJS := $(PUSH_SWAP_SRCS:.c=.o)

PUSH_SWAP_OBJS_BONUS := $(PRINTF_SRCS_BONUS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(PUSH_SWAP_OBJS)
	$(RM) $(PUSH_SWAP_OBJS_BONUS)

fclean : clean
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

bonus : $(BONUS_NAME)

$(NAME) : $(PUSH_SWAP_OBJS)
	$(CC) -o $@ $^

$(BONUS_NAME) : $(PUSH_SWAP_OBJS_BONUS)

run : $(NAME)
	./$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all bonus clean fclean re

