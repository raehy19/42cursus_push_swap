/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cal_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:02:58 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/19 22:03:01 by rjeong           ###   ########.fr       */
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

void	ft_cal_cmds_a(t_stack *a, t_stack *b, t_cmds *cmds)
{
	int		i;
	t_node	*temp;

	i = -1;
	temp = a->head;
	while (++i < a->size)
	{
		if (temp->is_sort == 0)
		{
			(cmds + i)->to_pop = a;
			(cmds + i)->to_push = b;
			ft_cal_r_to_pop(a, i, cmds + i);
			if (b->size > 1)
				ft_cal_r_push_b(temp->order, b, cmds + i, a->size + b->size);
			ft_cal_cmd_cnt(cmds + i);
		}
		else
			(cmds + i)->cmd_cnt = -1;
		temp = temp->next;
	}
}

void	ft_cal_cmds_b(t_stack *a, t_stack *b, t_cmds *cmds)
{
	int		i;
	t_node	*temp;

	i = -1;
	temp = b->head;
	while (++i < b->size)
	{
		(cmds + i)->to_pop = b;
		(cmds + i)->to_push = a;
		(cmds + i)->priority = temp->priority;
		ft_cal_r_to_pop(b, i, cmds + i);
		ft_cal_r_push_a(temp->order, a, cmds + i, a->size + b->size);
		ft_cal_cmd_cnt(cmds + i);
		if (ft_count_unsorted(a) > 0
			&& b->size < (a->size + b->size) * CRITERIA)
			(cmds + i)->cmd_cnt = -1;
		temp = temp->next;
	}
}

void	ft_set_priority(t_cmds *cmds, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if ((cmds + i)->priority == 1)
			break ;
	if (i != size)
	{
		i = -1;
		while (++i < size)
			if ((cmds + i)->priority == 0)
				(cmds + i)->cmd_cnt = -1;
	}
}

void	ft_cal_cmds(t_stack *a, t_stack *b, t_cmds *cmds)
{
	ft_cal_cmds_a(a, b, cmds);
	ft_cal_cmds_b(a, b, cmds + a->size);
	ft_set_priority(cmds + a->size, b->size);
}
