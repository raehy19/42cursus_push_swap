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

#include <printf.h>
#include "push_swap.h"

typedef struct s_lis_data
{
	int	order;
	int	i_len;
	int	prev_i;
}	t_lis_data;


typedef struct s_lis_orders
{
	int	size;
	int	*lis_orders;
}	t_lis_orders;


void	ft_init_lis_arr(t_lis_data *arr, t_node *start, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		(arr + i)->order = start->order;
		(arr + i)->i_len = 1;
		(arr + i)->prev_i = -1;
		start = start->next;
	}
}

t_lis_orders	ft_lis_list_ret(t_lis_data *arr, int len)
{
	t_lis_orders	ret;
	int				i;
	int				max_idx;

	max_idx = 0;
	i = 0;
	while (++i < len)
		if ((arr + i)->i_len > (arr + max_idx)->i_len)
			max_idx = i;
	ret.size = (arr + max_idx)->i_len;
	ret.lis_orders = (int *) malloc(sizeof(int) * (arr + max_idx)->i_len);
	i = -1;
	while (++i < ret.size)
	{
		*(ret.lis_orders + i) = (arr + max_idx)->order;
		max_idx = (arr + max_idx)->prev_i;
	}
	//debug
	printf("\n\nlis list :\n");
	for (int k = 0; k < ret.size; ++k)
	{
		printf("%5d", *(ret.lis_orders + k));
	}
	printf("\n\nlis size : %d\n\n", ret.size);
	//debug
	free(arr);
	return (ret);
}

t_lis_orders	ft_is_lis_list(t_node *start, int len)
{
	t_lis_data	*arr;
	int			i;
	int			j;

	arr = (t_lis_data *) malloc(sizeof(t_lis_data) * len);
	if (!arr)
		exit(7);
	ft_init_lis_arr(arr, start, len);
	i = 0;
	while (++i < len)
	{
		j = -1;
		while (++j < i)
		{
			if ((arr + j)->order < (arr + i)->order
				&& (arr + j)->i_len >= (arr + i)->i_len)
			{
				(arr + i)->i_len = (arr + j)->i_len + 1;
				(arr + i)->prev_i = j;
			}
		}
//		printf("arr + %2d    : %5d %5d %5d\n",i, (arr+i)->order,(arr+i)->i_len, (arr+i)->prev_i);
	}
	return (ft_lis_list_ret(arr, len));
}

int	ft_lis_len_ret(t_lis_data *arr, int len)
{
	int	ret;
	int	max_idx;
	int	i;

	max_idx = 0;
	i = 0;
	while (++i < len)
		if ((arr + i)->i_len > (arr + max_idx)->i_len)
			max_idx = i;
	ret = (arr + max_idx)->i_len;
	printf("max idx : %5d,  lis len : %5d\n", max_idx ,(arr+max_idx)->i_len);
	free(arr);
	return (ret);
}

int	ft_find_lis_len(t_node *start, int len)
{
	t_lis_data	*arr;
	int			i;
	int			j;

	arr = (t_lis_data *) malloc(sizeof(t_lis_data) * len);
	if (!arr)
		exit(7);
	ft_init_lis_arr(arr, start, len);
	i = 0;
	while (++i < len)
	{
		j = -1;
		while (++j < i)
		{
			if ((arr + j)->order < (arr + i)->order
				&& (arr + j)->i_len >= (arr + i)->i_len)
				(arr + i)->i_len = (arr + j)->i_len + 1;
		}
	}
	return (ft_lis_len_ret(arr, len));
}

t_node	*ft_find_l_lis_node(t_stack *a, int *lis_len)
{
	t_node	*tmp_node;
	t_node	*lis_longest_node;
	int		i;
	int		tmp_len;

	tmp_node = a->head->next;
	lis_longest_node = a->head;
	tmp_len = *lis_len;
	i = 0;
	while (++i < a->size)
	{
		if (*(lis_len + i) > tmp_len)
		{
			lis_longest_node = tmp_node;
			tmp_len = *(lis_len + i);
		}
		tmp_node = tmp_node->next;
	}
	free(lis_len);
	return (lis_longest_node);
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
				temp->is_lis = 1;
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
	ft_set_is_sort(a, ft_is_lis_list(ft_find_l_lis_node(a, lis_len), a->size));
}
