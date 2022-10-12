/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:35:23 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/11 18:35:25 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
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
				exit(6);
			if (temp->data < current->data)
				++(current->order);
			temp = temp->next;
		}
		current = current->next;
	}
}

typedef struct s_lis_find
{
	int	order;
	int	i_len;
	int	prev_i;
}	t_lis_data;

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

typedef struct s_is_lis_list
{
	int	size;
	int	*is_lis_list;
}	t_is_lis_list;

t_is_lis_list	ft_is_lis_list_n_size(t_lis_data *arr, int max_idx)
{
	t_is_lis_list	to_return;
	int			i;
	int			*is_lis;

	to_return.size = (arr + max_idx)->i_len;
	to_return.is_lis_list = (int *) malloc(sizeof(int) * (arr + max_idx)->i_len);
	i = -1;
	while (++i < (arr + max_idx)->i_len)
	{
		*(to_return.is_lis_list + i) = (arr + max_idx)->order;
		max_idx = (arr + max_idx)->prev_i;
	}
	//debug
	printf("\n\nlis list :\n");
	for (int k = 0; k < to_return.size; ++k)
	{
		printf("%5d", *(to_return.is_lis_list + k));
	}
	printf("\n\n");
	free(arr);
	return (to_return);
}

t_is_lis_list	ft_is_lis_list(t_node *start, int len)
{
	t_lis_data	*arr;
	int			max_idx;
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
				max_idx = i;
			}
		}
	}
	return (ft_is_lis_list_n_size(arr, max_idx));
}

int	ft_free_n_return(t_lis_data *to_free, int to_return)
{
	free(to_free);
	return (to_return);
}

int	ft_find_lis_len(t_node *start, int len)
{
	t_lis_data	*arr;
	int			max_idx;
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
				max_idx = i;
			}
		}
	}
	printf("max idx : %5d ,lis len : %5d\n",max_idx ,(arr+max_idx)->i_len);
	return (ft_free_n_return(arr, (arr + max_idx)->i_len));
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

void	ft_set_is_lis(t_stack *a, t_is_lis_list is_lis_arr)
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
			if (temp->order == *(is_lis_arr.is_lis_list + j))
				temp->is_lis = 1;
		temp = temp->next;
	}
	free(is_lis_arr.is_lis_list);
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
	ft_set_is_lis(a,
				  ft_is_lis_list(ft_find_l_lis_node(a, lis_len), a->size));
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	ft_init_stack(&a);
	ft_init_stack(&b);

	ft_parse_data(&a, ac, av);

	ft_stack_find_lis(&a);

	// debug
	t_node	*temp;
	temp = a.head;
	for (int k = 0; k < ac - 1; ++k)
	{
		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_lis);
		temp = temp->next;
	}
	printf("\nstack size : %d", a.size);
	return (0);
}
