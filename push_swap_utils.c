/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:47:59 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:20:42 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_data(t_stack *a, int ac, char **av)
{
	int		i;
	int		j;
	t_node	*temp;
	t_node	*current;

	i = 0;
	while (++i < ac)
		ft_push_stack_data(a, ft_atoi(*(av + i)));
	current = a->head;
	i = -1;
	while (++i < a->size)
	{
		temp = current->next;
		j = -1;
		while (++j < a->size - 1)
		{
			if (temp->data == current->data)
				ft_error(7);
			if (temp->data < current->data)
				++(current->order);
			temp = temp->next;
		}
		current = current->next;
	}
}

int	ft_count_unsorted(t_stack *stack)
{
	t_node	*temp;
	int		cnt;
	int		i;

	cnt = 0;
	temp = stack->head;
	i = -1;
	while (++i < stack->size)
	{
		if (temp->is_sort == 0)
			++cnt;
		temp = temp->next;
	}
	return (cnt);
}

void	ft_init_cmds(t_cmds **cmds, int size)
{
	int	i;

	*cmds = (t_cmds *) malloc(sizeof(t_cmds) * (size));
	if (!(*cmds))
		ft_error(3);
	i = -1;
	while (++i < size)
	{
		((*cmds) + i)->ra = 0;
		((*cmds) + i)->rra = 0;
		((*cmds) + i)->rb = 0;
		((*cmds) + i)->rrb = 0;
		((*cmds) + i)->rr = 0;
		((*cmds) + i)->rrr = 0;
		((*cmds) + i)->to_pop = NULL;
		((*cmds) + i)->to_push = NULL;
		((*cmds) + i)->cmd_cnt = 0;
		((*cmds) + i)->priority = 0;
	}
}

int	ft_if_three_node(t_stack *a, t_stack *b)
{
	if (a->size == 3 && b->size == 0)
	{
		if (a->head->order == 0 && a->head->next->order == 2)
		{
			ft_reverse_rotate(a);
			ft_swap(a);
			return (1);
		}
		if (a->head->order == 2 && a->head->next->order == 1)
		{
			ft_rotate(a);
			ft_swap(a);
			return (1);
		}
	}
	return (0);
}

void	ft_final_sort(t_stack *stack)
{
	t_node	*temp;
	int		cnt;
	int		i;

	temp = stack->head;
	cnt = 0;
	i = -1;
	while (temp->order != 0)
	{
		temp = temp->next;
		++cnt;
	}
	if (cnt > stack->size / 2)
		while (++i < stack->size - cnt)
			ft_reverse_rotate(stack);
	else
		while (++i < cnt)
			ft_rotate(stack);
}
