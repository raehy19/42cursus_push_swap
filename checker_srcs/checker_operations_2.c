/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:27:55 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:20:32 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rotate_rotate(t_stack *stack1, t_stack *stack2)
{
	if (stack1->size > 1)
		stack1->head = stack1->head->next;
	if (stack2->size > 1)
		stack2->head = stack2->head->next;
}

void	ft_reverse_rotate_rotate(t_stack *stack1, t_stack *stack2)
{
	if (stack1->size > 1)
		stack1->head = stack1->head->prev;
	if (stack2->size > 1)
		stack2->head = stack2->head->prev;
}

void	ft_swap_swap(t_stack *stack1, t_stack *stack2)
{
	t_node	*temp1;
	t_node	*temp2;

	if (stack1->size > 1)
	{
		temp1 = ft_pop_stack_node(stack1);
		stack1->head = stack1->head->next;
		ft_push_stack_node(stack1, temp1);
		stack1->head = stack1->head->prev;
	}
	if (stack2->size > 1)
	{
		temp2 = ft_pop_stack_node(stack2);
		stack2->head = stack2->head->next;
		ft_push_stack_node(stack2, temp2);
		stack2->head = stack2->head->prev;
	}
}
