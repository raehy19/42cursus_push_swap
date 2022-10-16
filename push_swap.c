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

void	ft_init_commands(t_commands *commands, int size)
{
	int	i;

	commands = (t_commands *)	malloc(sizeof(t_commands) * (size));
	if (!commands)
		ft_error(3);
	i = -1;
	while (++i < size)
	{
		(commands + i)->ra = 0;
		(commands + i)->rra = 0;
		(commands + i)->rb = 0;
		(commands + i)->rrb = 0;
		(commands + i)->rr = 0;
		(commands + i)->rrr = 0;
		(commands + i)->to_pop =  NULL;
		(commands + i)->to_push =  NULL;
		(commands + i)->cmd_cnt = 0;
	}
}

void	ft_find_appropriate(int order, t_stack *to_pop, t_stack *to_push, t_commands *commands)
{

}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	t_commands	*commands;

	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	ft_parse_data(&a, ac, av);
	ft_stack_find_lis(&a);

	ft_init_commands(commands, a.size + b.size);

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
	while (ft_count_unsorted(&a) > 0)
	{
		if (a.head->is_sort == 0)
			ft_push(&a, &b);
		else
		{
			if (a.head->is_sort == 1
				&& (a.head->prev->is_sort == 1
				&& a.head->next->is_sort == 0
				&& a.head->next->order < a.head->order
				&& a.head->next->order > a.head->prev->order)
				|| (a.head->order > 0
				&& a.head->order - 1 == a.head->next->order)
				|| (a.head->order == 0
				&& a.head->next->order == a.size - 1))
			{
				ft_swap(&a);
				a.head->is_sort = 1;
			}
			else
				ft_rotate(&a);
		}
	}


	printf("\nunsorted : %d\n", ft_count_unsorted(&a));
	if (ft_count_unsorted(&a) == 0)
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
