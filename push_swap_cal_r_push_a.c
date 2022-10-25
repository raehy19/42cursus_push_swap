/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cal_r_push_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:08:47 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/19 22:08:48 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_u_max_o_min
{
	int	under_max;
	int	u_max_idx;
	int	over_min;
	int	o_min_idx;
}	t_u_max_o_min;

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
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
			data->u_max_idx = i;
		}
		if (tmp->is_sort == 1
			&& tmp->order > order && tmp->order < data->over_min)
		{
			data->over_min = tmp->order;
			data->o_min_idx = i;
		}
		tmp = tmp->next;
	}
}

void	ft_is_max_or_min(t_u_max_o_min *data, t_stack *a)
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
			data->u_max_idx = i;
		}
		if (tmp->is_sort == 1 && tmp->order < data->over_min)
		{
			data->over_min = tmp->order;
			data->o_min_idx = i;
		}
		tmp = tmp->next;
	}
}

void	ft_cal_cmds_push_a(t_u_max_o_min *data, int a_size, t_cmds *cmds)
{
	data->u_max_idx += 1;
	if (data->u_max_idx == a_size)
		data->u_max_idx -= a_size;
//	printf("\numax : %d omin : %d\n", data->u_max_idx, data->o_min_idx);
	cmds->ra = ft_min(data->u_max_idx, data->o_min_idx);
	cmds->rra = ft_min(a_size - data->u_max_idx, a_size - data->o_min_idx);
//	printf("\nra : %d rra : %d\n", cmds->ra, cmds->rra);
}

// check order location in sorted
void	ft_cal_r_push_a(int order, t_stack *a, t_cmds *cmds, int max_order)
{
	t_u_max_o_min	data;

	data = (t_u_max_o_min) {-1, -1, max_order, -1};
	ft_cal_locate(&data, a, order);
	if (data.u_max_idx == -1 || data.o_min_idx == -1)
	{
		data = (t_u_max_o_min) {-1, -1, max_order, -1};
		ft_is_max_or_min(&data, a);
	}
	ft_cal_cmds_push_a(&data, a->size, cmds);
}
