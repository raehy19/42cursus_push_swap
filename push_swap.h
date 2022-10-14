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

typedef struct s_node	t_node;

struct s_node
{
	int		data;
	int		order;
	int		is_sort;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	t_node	*head;
	int		size;
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

void	ft_error(int error_code);

int		ft_atoi(const char *str);

void	ft_init_stack(t_stack *stack);
void	ft_push_stack_node(t_stack *stack, t_node *node);
void	ft_push_stack_data(t_stack *stack, int data);
t_node	*ft_pop_stack_node(t_stack *stack);
void	ft_clear_stack(t_stack *stack);

void	ft_stack_find_lis(t_stack *a);

#endif
