/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:35:23 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/11 18:35:25 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error_code)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(error_code);
}

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
	printf("\ncnt : %d\n",cnt);
	if (cnt > stack->size / 2)
		while (++i < stack->size - cnt)
			ft_reverse_rotate(stack);
	else
		while (++i < cnt)
			ft_rotate(stack);
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
	}
}

void	ft_is_swappable(t_stack *a)
{
	if ((a->head->is_sort == 1 && a->head->next->is_sort == 0)
		&& ((a->head->prev->is_sort == 1
			 && a->head->next->order < a->head->order
			 && a->head->next->order > a->head->prev->order)
			|| (a->head->order > 0
				&& a->head->order - 1 == a->head->next->order)
			|| (a->head->order == 0
				&& a->head->next->order == a->size - 1)))
	{
		ft_swap(&a);
		a->head->is_sort = 1;
	}
}

void	ft_cal_r_to_pop(t_stack *to_pop, int i, t_cmds *cmds)
{
	if (to_pop->stack_name == 'a')
	{
		if (i > to_pop->size / 2)
			cmds->rra = to_pop->size - i;
		else
			cmds->ra = i;
	}
	else if (to_pop->stack_name == 'b')
	{
		if (i > to_pop->size / 2)
			cmds->rrb = to_pop->size - i;
		else
			cmds->rb = i;
	}
}

void	ft_cal_r_to_push(int order, t_stack *to_push, t_cmds *cmds)
{
	t_node	*temp;

	temp = to_push->head;

}

void	ft_cal_cmd_cnt(t_cmds *cmds)
{

}

void	ft_cal_r(t_stack *to_pop, t_stack *to_push, t_cmds *cmds, int i)
{
	ft_cal_r_to_pop(to_pop, i, cmds);
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
			ft_cal_r_to_pop(a, i, cmds + i);
			ft_cal_r_to_push(temp->order, b, cmds + i);
			ft_cal_cmd_cnt(cmds + i);
		}
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
		if (temp->is_sort == 0)
		{
			ft_cal_r_to_pop(b, i - a->size, cmds + i);
			ft_cal_r_to_push(temp->order, a, cmds + i);
			ft_cal_cmd_cnt(cmds + i);
		}
		temp = temp->next;
	}
}


int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_cmds	*cmds;

	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	ft_parse_data(&a, ac, av);
	ft_stack_find_lis(&a);


	// debug
	t_node	*temp;
	temp = a.head;
	for (int k = 0; k < a.size; ++k)
	{
		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
		temp = temp->next;
	}
	printf("\nstack size : %d", a.size);


	// b 정렬 확인 :
	// 1. order가 b에서 가장 길다면 head < order && tail < order
	// 2. 아닐 경우 head < order && tail > order 일때 삽입

	// test : push unsorted to b & swap if can
	while (ft_count_unsorted(&a) + ft_count_unsorted(&b) > 0)
	{
		ft_is_swappable(&a);
		ft_init_cmds(&cmds, a.size + b.size); // == ac - 1 ?
		free(cmds);
	}


//	printf("\nunsorted : %d\n", ft_count_unsorted(&a));
//	if (ft_count_unsorted(&a) == 0)
//		ft_final_sort(&a);


	ft_final_sort(&a);


//	// debug
	//print a
	printf("stack %c\n", a.stack_name);
	temp = a.head;
	for (int k = 0; k < a.size; ++k)
	{
		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
		temp = temp->next;
	}
	printf("\na stack size : %d\n\n", a.size);


	//print b
	printf("stack %c\n", b.stack_name);
	temp = b.head;
	for (int k = 0; k < b.size; ++k)
	{
		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
		temp = temp->next;
	}
	printf("\nb stack size : %d\n\n", b.size);
	return (0);
}
