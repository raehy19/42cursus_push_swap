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
CFLAGS := -g  -Wall -Wextra -Werror -MMD -MP
RM := rm -f

PUSH_SWAP_SRCS := \
	push_swap.c \
	ft_error.c \
	ft_atoi.c \
	push_swap_utils.c \
	push_swap_lis_1.c \
	push_swap_lis_2.c \
	push_swap_stack_ctl.c \
	push_swap_operations_1.c \
	push_swap_operations_2.c \
	push_swap_ft_is_swappable.c \
	push_swap_cal_cmds.c \
	push_swap_cal_r_push_a.c \
	push_swap_cal_r_push_b.c \
	push_swap_cal_cmd_cnt.c \
	push_swap_execute_functions.c \

PUSH_SWAP_SRCS_BONUS := \
	checker.c \
	ft_atoi.c \
	ft_error.c \
	ft_strcmp.c \
	get_next_line.c \
	checker_operations_1.c \
	checker_operations_2.c \
	checker_stack_ctl.c \

all : $(NAME)

bonus : $(BONUS_NAME)

both :
	make all
	make bonus

PUSH_SWAP_OBJS := $(addprefix push_swap_srcs/, $(PUSH_SWAP_SRCS:.c=.o))

PUSH_SWAP_OBJS_BONUS := $(addprefix checker_srcs/, $(PUSH_SWAP_SRCS_BONUS:.c=.o))

PUSH_SWAP_DEPS := $(addprefix push_swap_srcs/, $(PUSH_SWAP_SRCS:.c=.d))

PUSH_SWAP_DEPS_BONUS := $(addprefix checker_srcs/, $(PUSH_SWAP_SRCS_BONUS:.c=.d))

-include $(PUSH_SWAP_DEPS) $(PUSH_SWAP_DEPS_BONUS)

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

$(NAME) : $(PUSH_SWAP_OBJS)
	$(CC) $^ -o $@

$(BONUS_NAME) : $(PUSH_SWAP_OBJS_BONUS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all bonus clean fclean re
