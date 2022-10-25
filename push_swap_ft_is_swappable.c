/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft_is_swappable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:03:55 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/19 22:03:56 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_prev_swap(t_node *node)
{
	t_node	*prev;

	prev = node->prev;
	while (prev->is_sort != 1)
		prev = prev->prev;
	if ((node->is_sort == 1 && node->next->is_sort == 0)
		&& ((node->next->order < node->order
				&& prev->order < node->next->order)
			|| ((prev->order > node->order)
				&& (node->next->order > prev->order
					|| node->next->order < node->order))))
		return (1);
	return (0);
}

int	ft_check_next_swap(t_node *node)
{
	t_node	*next;

	next = node->next->next;
	while (next->is_sort != 1)
		next = next->next;
	if ((node->is_sort == 0 && node->next->is_sort == 1)
		&& ((node->next->order < node->order
				&& node->next->order < next->order)
			|| ((next->order < node->next->order)
				&& (node->order > next->order
					|| node->order > node->next->order))))
		return (1);
	return (0);
}

void	ft_is_swappable(t_stack *a)
{
	if (ft_check_prev_swap(a->head))
	{
		ft_swap(a);
		a->head->is_sort = 1;
	}
	if (ft_check_next_swap(a->head))
	{
		ft_swap(a);
		a->head->next->is_sort = 1;
	}
	if (ft_check_prev_swap(a->head->next))
	{
		ft_rotate(a);
		ft_swap(a);
		a->head->is_sort = 1;
	}
	if (ft_check_next_swap(a->head->next))
	{
		ft_rotate(a);
		ft_swap(a);
		a->head->next->is_sort = 1;
	}
}
