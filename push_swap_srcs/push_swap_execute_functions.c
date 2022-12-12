/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_execute_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 04:46:39 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:20:07 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_rotate(int n, t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_rotate(stack);
}

void	ft_execute_reverse_rotate(int n, t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_reverse_rotate(stack);
}

void	ft_execute_rotate_rotate(int n, t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_rotate_rotate(a, b);
}

void	ft_execute_reverse_rotate_rotate(int n, t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_reverse_rotate_rotate(a, b);
}

void	ft_execute_min_cnt_cmds(t_stack *a, t_stack *b, t_cmds *cmds, int size)
{
	t_cmds	*min_cmds;
	int		i;

	i = 0;
	while ((cmds + i)->cmd_cnt < 0)
		++i;
	min_cmds = (cmds + i);
	while (++i < size)
	{
		if ((cmds + i)->cmd_cnt > -1 && (cmds + i)->cmd_cnt < min_cmds->cmd_cnt)
			min_cmds = (cmds + i);
	}
	ft_execute_rotate(min_cmds->ra, a);
	ft_execute_reverse_rotate(min_cmds->rra, a);
	ft_execute_rotate(min_cmds->rb, b);
	ft_execute_reverse_rotate(min_cmds->rrb, b);
	ft_execute_rotate_rotate(min_cmds->rr, a, b);
	ft_execute_reverse_rotate_rotate(min_cmds->rrr, a, b);
	ft_push(min_cmds->to_pop, min_cmds->to_push);
}
