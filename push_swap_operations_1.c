/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:53 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/14 17:27:34 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	stack->head = stack->head->next;
	write(STDOUT_FILENO, "r", 1);
	write(STDOUT_FILENO, &(stack->stack_name), 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_reverse_rotate(t_stack *stack)
{
	stack->head = stack->head->prev;
	write(STDOUT_FILENO, "rr", 2);
	write(STDOUT_FILENO, &(stack->stack_name), 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_swap(t_stack *stack)
{
	t_node	*temp;

	temp = ft_pop_stack_node(stack);
	ft_rotate(stack);
	ft_push_stack_node(stack, temp);
	ft_reverse_rotate(stack);
	write(STDOUT_FILENO, "s", 1);
	write(STDOUT_FILENO, &(stack->stack_name), 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_push(t_stack *to_pop, t_stack *to_push)
{
	ft_push_stack_node(to_push, ft_pop_stack_node(to_pop));
	write(STDOUT_FILENO, "p", 1);
	write(STDOUT_FILENO, &(to_push->stack_name), 1);
	write(STDOUT_FILENO, "\n", 1);
}
