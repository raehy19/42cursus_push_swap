/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:53 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/14 16:32:54 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	stack->head = stack->head->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	stack->head = stack->head->prev;
}

void	ft_swap(t_stack *stack)
{
	t_node	*temp;

	temp = ft_pop_stack_node(stack);
	ft_rotate(stack);
	ft_push_stack_node(stack, temp);
}

void	ft_push(t_stack *to_pop, t_stack *to_push)
{
	ft_push_stack_node(to_push, ft_pop_stack_node(to_pop));
}
