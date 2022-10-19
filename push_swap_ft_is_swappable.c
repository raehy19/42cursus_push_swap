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

void	ft_is_swappable(t_stack *a)
{
	if ((a->head->is_sort == 1 && a->head->next->is_sort == 0)
		&& ((a->head->prev->is_sort == 1
				&& a->head->next->order < a->head->order
				&& a->head->next->order > a->head->prev->order)
			|| (a->head->order > 0
				&& a->head->order - 1 == a->head->next->order)
			|| (a->head->order == 0
				&& a->head->next->order == a->size - 1)))
	{
		ft_swap(a);
		a->head->is_sort = 1;
	}
}
