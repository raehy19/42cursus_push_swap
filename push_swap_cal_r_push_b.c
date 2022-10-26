/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cal_r_push_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:46:53 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:20:02 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_max_order
{
	int	order;
	int	idx;
}	t_max_order;

void	ft_cal_locate_b(t_max_order *max, t_stack *b, int order)
{
	t_node	*tmp;
	int		i;

	tmp = b->head;
	i = -1;
	while (++i < b->size)
	{
		if (tmp->order < order && tmp->order > max->order)
		{
			max->order = tmp->order;
			max->idx = i;
		}
		tmp = tmp->next;
	}
}

void	ft_find_max(t_max_order *max, t_stack *b)
{
	t_node	*tmp;
	int		i;

	tmp = b->head->next;
	max->order = b->head->order;
	max->idx = 0;
	i = 0;
	while (++i < b->size)
	{
		if (tmp->order > max->order)
		{
			max->order = tmp->order;
			max->idx = i;
		}
		tmp = tmp->next;
	}
}

void	ft_cal_r_push_b(int order, t_stack *b, t_cmds *cmds, int max_order)
{
	t_max_order	max;

	max = (t_max_order){-1, -1};
	ft_cal_locate_b(&max, b, order);
	if (max.idx == -1)
		ft_find_max(&max, b);
	cmds->rb = max.idx;
	cmds->rrb = b->size - max.idx;
	if (b->size > max_order * CRITERIA)
	{
		cmds->rb = 0;
		cmds->rrb = 0;
	}
}
