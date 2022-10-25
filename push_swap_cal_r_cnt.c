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


// push a

typedef struct s_u_max_o_min
{
	int	under_max;
	int	under_max_idx;
	int	over_min;
	int	over_min_idx;
}	t_u_max_o_min;

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_is_max_or_min(t_u_max_o_min *data, t_stack *a, int order)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (tmp->is_sort == 1 && tmp->order > data->under_max)
		{
			data->under_max = tmp->order;
			data->under_max_idx = i;
		}
		if (tmp->is_sort == 1 && tmp->order < data->over_min)
		{
			data->over_min = tmp->order;
			data->over_min_idx = i;
		}
		tmp = tmp->next;
	}
}

void	ft_cal_cmds_push_a(t_u_max_o_min *data, int a_size, t_cmds *cmds)
{

}

void	ft_cal_locate(t_u_max_o_min *data, t_stack *a, int order)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	i = -1;
	while (++i < a->size)
	{
		if (tmp->is_sort == 1
			&& tmp->order < order && tmp->order > data->under_max)
		{
			data->under_max = tmp->order;
			data->under_max_idx = i;
		}
		if (tmp->is_sort == 1
			&& tmp->order > order && tmp->order < data->over_min)
		{
			data->over_min = tmp->order;
			data->over_min_idx = i;
		}
		tmp = tmp->next;
	}
}

// check order location in sorted
void	ft_cal_r_push_a(int order, t_stack *a, t_cmds *cmds, int max_order)
{
	t_u_max_o_min	data;

	data = (t_u_max_o_min) {-1, -1, -1, max_order};
	ft_cal_locate(&data, a, order);
	if (data.under_max_idx == -1 || data.over_min_idx == -1)
	{
		data = (t_u_max_o_min) {-1, -1, -1, max_order};
		ft_is_max_or_min(&data, a, order);
	}
	// cal cmds
}
