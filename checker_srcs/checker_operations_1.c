/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:32:53 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:20:30 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate(t_stack *stack)
{
	if (stack->size > 1)
		stack->head = stack->head->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->size > 1)
		stack->head = stack->head->prev;
}

void	ft_swap(t_stack *stack)
{
	t_node	*temp;

	if (stack->size > 1)
	{
		temp = ft_pop_stack_node(stack);
		stack->head = stack->head->next;
		ft_push_stack_node(stack, temp);
		stack->head = stack->head->prev;
	}
}

void	ft_push(t_stack *to_pop, t_stack *to_push)
{
	if (to_pop->size > 0)
	{
		ft_push_stack_node(to_push, ft_pop_stack_node(to_pop));
	}
}
