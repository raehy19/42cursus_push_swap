/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_stack_ctl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:47 by rjeong            #+#    #+#             */
/*   Updated: 2022/12/12 13:17:49 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void	ft_push_stack_node(t_stack *stack, t_node *node)
{
	if (stack->size == 1)
	{
		stack->head->next = node;
		stack->head->prev = node;
		node->next = stack->head;
		node->prev = stack->head;
	}
	else if (stack->size > 1)
	{
		node->prev = stack->head->prev;
		node->next = stack->head;
		stack->head->prev->next = node;
		stack->head->prev = node;
	}
	stack->head = node;
	++(stack->size);
}

void	ft_push_stack_data(t_stack *stack, int data)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		ft_error(3);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	ft_push_stack_node(stack, node);
	if (stack->size > 1)
		stack->head = stack->head->next;
}

t_node	*ft_pop_stack_node(t_stack *stack)
{
	t_node	*ret;

	if (stack->size < 1)
		return (NULL);
	else if (stack->size == 1)
	{
		stack->head->prev = NULL;
		stack->head->next = NULL;
		ret = stack->head;
		stack->head = NULL;
	}
	else
	{
		stack->head->prev->next = stack->head->next;
		stack->head->next->prev = stack->head->prev;
		ret = stack->head;
		stack->head = stack->head->next;
		ret->prev = NULL;
		ret->next = NULL;
	}
	--(stack->size);
	return (ret);
}

void	ft_clear_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->size > 0)
	{
		temp = stack->head;
		while (--(stack->size) > 0)
		{
			temp = temp->next;
			free(temp->prev);
		}
		free(temp);
		stack->head = NULL;
	}
}
