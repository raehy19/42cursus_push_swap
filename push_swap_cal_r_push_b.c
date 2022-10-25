/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cal_r_push_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:46:53 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/25 12:46:55 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

