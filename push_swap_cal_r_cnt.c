/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cal_r_cnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:08:47 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/19 22:08:48 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cal_r_to_pop(t_stack *to_pop, int i, t_cmds *cmds)
{
	if (to_pop->stack_name == 'a')
	{
		cmds->ra = i;
		cmds->rra = to_pop->size - i;
	}
	else if (to_pop->stack_name == 'b')
	{
		cmds->rb = i;
		cmds->rrb = to_pop->size - i;
	}
}

int	ft_is_order_biggest(int order, t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = -1;
	temp = stack->head;
	while (++i < stack->size)
	{
		if (temp->order > order)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_cal_r_push_b(int order, t_stack *b, t_cmds *cmds)
{
	t_node	*temp;
	int		i;

	temp = b->head;
	i = -1;
	if (ft_is_order_biggest(order, b) == 1)
	{
		while (++i < b->size)
		{
			if (temp->prev->order < order && temp->order < order)
				break ;
			temp = temp->next;
		}
	}
	else
	{
		while (++i < b->size)
		{
			if (temp->prev->order > order && temp->order < order)
				break ;
			temp = temp->next;
		}
	}
	cmds->rb = i;
	cmds->rrb = b->size - i;
}

void	ft_cal_r_push_a(int order, t_stack *a, t_cmds *cmds)
{
	t_node	*temp;
	int		i;

	temp = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (temp->prev->is_sort == 1 && temp->prev->order > order)
			break ;
		temp = temp->next;
	}
	cmds->rra = a->size - i;
	temp = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (temp->is_sort == 1 && temp->order < order)
			break ;
		temp = temp->prev;
	}
	cmds->ra = a->size - i + 1;
}
