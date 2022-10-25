/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:35:29 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/11 18:35:35 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <printf.h>

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define CRITERIA 1

typedef struct s_node	t_node;

struct s_node
{
	int		data;
	int		order;
	int		is_sort;
	int		priority;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	t_node	*head;
	int		size;
	char	stack_name;
}	t_stack;

typedef struct s_lis_data
{
	int	order;
	int	i_len;
	int	prev_i;
}	t_lis_data;

typedef struct s_lis_orders
{
	int	size;
	int	*lis_orders;
}	t_lis_orders;

typedef struct s_cmds
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	t_stack	*to_pop;
	t_stack	*to_push;
	int		cmd_cnt;
	int		priority;
}	t_cmds;

void	ft_error(int error_code);

int		ft_atoi(const char *str);

void	ft_init_stack(t_stack *stack, char stack_name);
void	ft_push_stack_node(t_stack *stack, t_node *node);
void	ft_push_stack_data(t_stack *stack, int data);
t_node	*ft_pop_stack_node(t_stack *stack);
void	ft_clear_stack(t_stack *stack);

void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
void	ft_push(t_stack *to_pop, t_stack *to_push);
void	ft_reverse_rotate_rotate(t_stack *stack1, t_stack *stack2);
void	ft_rotate_rotate(t_stack *stack1, t_stack *stack2);
void	ft_swap_swap(t_stack *stack1, t_stack *stack2);
void	ft_swap(t_stack *stack);

void	ft_stack_find_lis(t_stack *a);

int		ft_count_unsorted(t_stack *stack);

void	ft_is_swappable(t_stack *a);

void	ft_cal_r_push_b(int order, t_stack *b, t_cmds *cmds, int max_order);
void	ft_cal_r_push_a(int order, t_stack *a, t_cmds *cmds, int max_order);

void	ft_cal_cmds(t_stack *a, t_stack *b, t_cmds *cmds);

void	ft_cal_cmd_cnt(t_cmds *cmds);

void	ft_execute_min_cnt_cmds(t_stack *a, t_stack *b, t_cmds *cmds, int size);

#endif
