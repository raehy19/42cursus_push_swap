/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cal_cmd_cnt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:57:02 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:19:42 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_cmd_optimize_ra_rb(t_cmds *cmds)
{
	if (cmds->ra > cmds->rb)
	{
		cmds->rr = cmds->rb;
		cmds->ra -= cmds->rb;
		cmds->rb = 0;
	}
	else
	{
		cmds->rr = cmds->ra;
		cmds->rb -= cmds->ra;
		cmds->ra = 0;
	}
	cmds->rra = 0;
	cmds->rrb = 0;
}

void	ft_cmd_optimize_rra_rrb(t_cmds *cmds)
{
	if (cmds->rra > cmds->rrb)
	{
		cmds->rrr = cmds->rrb;
		cmds->rra -= cmds->rrb;
		cmds->rrb = 0;
	}
	else
	{
		cmds->rrr = cmds->rra;
		cmds->rrb -= cmds->rra;
		cmds->rra = 0;
	}
	cmds->ra = 0;
	cmds->rb = 0;
}

void	ft_cmd_optimization(t_cmds *cmds, int idx)
{
	if (idx == 0)
		ft_cmd_optimize_ra_rb(cmds);
	else if (idx == 1)
		ft_cmd_optimize_rra_rrb(cmds);
	else if (idx == 2)
	{
		cmds->ra = 0;
		cmds->rrb = 0;
	}
	else if (idx == 3)
	{
		cmds->rra = 0;
		cmds->rb = 0;
	}
}

void	ft_cal_cmd_cnt(t_cmds *cmds)
{
	int	cnts[4];
	int	i;
	int	min_val;
	int	min_idx;

	*(cnts) = ft_max(cmds->ra, cmds->rb);
	*(cnts + 1) = ft_max(cmds->rra, cmds->rrb);
	*(cnts + 2) = cmds->rra + cmds->rb;
	*(cnts + 3) = cmds->ra + cmds->rrb;
	i = 0;
	min_idx = 0;
	min_val = *cnts;
	while (++i < 4)
	{
		if (*(cnts + i) < min_val)
		{
			min_idx = i;
			min_val = *(cnts + i);
		}
	}
	ft_cmd_optimization(cmds, min_idx);
	cmds->cmd_cnt = min_val;
}
