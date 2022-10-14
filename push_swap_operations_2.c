/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:27:55 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/14 17:27:56 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_rotate(t_stack *stack1, t_stack *stack2)
{
	stack1->head = stack1->head->next;
	stack2->head = stack2->head->next;
	write(STDOUT_FILENO, "rr\n", 3);
}

void	ft_reverse_rotate_rotate(t_stack *stack1, t_stack *stack2)
{
	stack1->head = stack1->head->prev;
	stack2->head = stack2->head->prev;
	write(STDOUT_FILENO, "rrr\n", 4);
}

void	ft_swap_swap(t_stack *stack1, t_stack *stack2)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = ft_pop_stack_node(stack1);
	temp2 = ft_pop_stack_node(stack2);
	stack1->head = stack1->head->next;
	stack2->head = stack2->head->next;
	ft_push_stack_node(stack1, temp1);
	ft_push_stack_node(stack2, temp2);
	stack1->head = stack1->head->prev;
	stack2->head = stack2->head->prev;
	write(STDOUT_FILENO, "ss\n", 3);
}
