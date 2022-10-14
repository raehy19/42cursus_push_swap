/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:09:49 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/13 22:09:51 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(arr);
	return (ret);
}

t_lis_orders	ft_find_lis_list(t_node *start, int len)
{
	t_lis_data	*arr;
	int			i;
	int			j;

	arr = (t_lis_data *) malloc(sizeof(t_lis_data) * len);
	if (!arr)
		ft_error(3);
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
		ft_error(3);
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
