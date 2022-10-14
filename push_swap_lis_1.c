/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:09:34 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/13 22:09:35 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lis_orders	ft_find_lis_list(t_node *start, int len);
int	ft_find_lis_len(t_node *start, int len);

t_node	*ft_max_lis_node(t_stack *a, int *lis_len)
{
	t_node	*tmp_node;
	t_node	*max_lis_node;
	int		i;
	int		tmp_len;

	tmp_node = a->head->next;
	max_lis_node = a->head;
	tmp_len = *lis_len;
	i = 0;
	while (++i < a->size)
	{
		if (*(lis_len + i) > tmp_len)
		{
			max_lis_node = tmp_node;
			tmp_len = *(lis_len + i);
		}
		tmp_node = tmp_node->next;
	}
	free(lis_len);
	return (max_lis_node);
}

void	ft_set_is_sort(t_stack *a, t_lis_orders is_lis_arr)
{
	t_node	*temp;
	int		i;
	int		j;

	temp = a->head;
	i = -1;
	while (++i < a->size)
	{
		j = -1;
		while (++j < is_lis_arr.size)
			if (temp->order == *(is_lis_arr.lis_orders + j))
				temp->is_sort = 1;
		temp = temp->next;
	}
	free(is_lis_arr.lis_orders);
}

void	ft_stack_find_lis(t_stack *a)
{
	t_node	*temp;
	int		*lis_len;
	int		i;

	temp = a->head;
	lis_len = (int *) malloc(sizeof(int) * a->size);
	if (!lis_len)
		exit(7);
	i = -1;
	while (++i < a->size)
	{
		*(lis_len + i) = ft_find_lis_len(temp, a->size);
		temp = temp->next;
	}
	ft_set_is_sort(a, ft_find_lis_list(ft_max_lis_node(a, lis_len), a->size));
}
