/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:35:23 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/11 18:35:25 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void	ft_push_stack_node(t_stack *stack, t_node *node)
{
	if (stack->size == 1)
	{
		(*(stack->head))->next = node;
		(*(stack->head))->prev = node;
		node->next = (*(stack->head));
		node->prev = (*(stack->head));
	}
	else if (stack->size > 1)
	{
		(*(stack->head))->prev->next = node;
		(*(stack->head))->next->prev = node;
		node->prev = (*(stack->head))->prev;
		node->next = (*(stack->head));
		*(stack->head) = node;
	}
	*(stack->head) = node;
	++(stack->size);
}

void	ft_push_stack_data(t_stack *stack, int data)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	node->data = data;
	node->order = 0;
	node->prev = NULL;
	node->next = NULL;
	ft_push_stack_node(stack, node);
}

t_node	*ft_pop_stack_node(t_stack *stack)
{
	t_node	*temp;

	temp = NULL;
	if (stack->size == 1)
	{
		(*(stack->head))->prev = NULL;
		(*(stack->head))->next = NULL;
		temp = *(stack->head);
		(*(stack->head)) = NULL;
	}
	else if (stack->size > 1)
	{
		(*(stack->head))->prev->next = (*(stack->head))->next;
		(*(stack->head))->next->prev = (*(stack->head))->prev;
		(*(stack->head))->prev = NULL;
		(*(stack->head))->next = NULL;
		temp = *(stack->head);
		*(stack->head) = (*(stack->head))->next;
	}

	return (temp);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a);
	ft_init_stack(&b);
	return (0);
}
