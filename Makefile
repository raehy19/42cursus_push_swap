# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 15:12:29 by rjeong            #+#    #+#              #
#    Updated: 2022/09/06 15:12:32 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS_NAME := checker
CC := cc
CFLAGS := -g # -Wall -Wextra -Werror
RM := rm -f

PUSH_SWAP_SRCS := \
	push_swap.c \
	push_swap_lis_1.c \
	push_swap_lis_2.c \
	push_swap_stack_ctl.c \
	push_swap_operations_1.c \
	push_swap_operations_2.c \
	ft_atoi.c \

PUSH_SWAP_SRCS_BONUS := \

all : $(NAME)

bonus : $(BONUS_NAME)

PUSH_SWAP_OBJS := $(PUSH_SWAP_SRCS:.c=.o)

PUSH_SWAP_OBJS_BONUS := $(PRINTF_SRCS_BONUS:.c=.o)

PUSH_SWAP_DEPS := $(PUSH_SWAP_SRCS:.c=.d)

PUSH_SWAP_DEPS_BONUS := $(PRINTF_SRCS_BONUS:.c=.d)

clean :
	$(RM) $(PUSH_SWAP_OBJS)
	$(RM) $(PUSH_SWAP_OBJS_BONUS)
	$(RM) $(PUSH_SWAP_DEPS)
	$(RM) $(PUSH_SWAP_DEPS_BONUS)

fclean : clean
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

-include $(PUSH_SWAP_DEPS) $(PUSH_SWAP_DEPS_BONUS)

$(NAME) : $(PUSH_SWAP_OBJS)
	$(CC) -o $@ $^

$(BONUS_NAME) : $(PUSH_SWAP_OBJS_BONUS)

run : $(NAME)
	./$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all bonus clean fclean re
