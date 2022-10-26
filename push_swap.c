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
		((*cmds) + i)->priority = 0;
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

//	// debug
//	t_node	*temp;
//	temp = a.head;
//	for (int k = 0; k < a.size; ++k)
//	{
//		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
//		temp = temp->next;
//	}
//	printf("\nstack size : %d\n", a.size);
//

	while (ft_count_unsorted(&a) + ft_count_unsorted(&b) > 0)
	{
		ft_is_swappable(&a);
		if (ft_count_unsorted(&a) + ft_count_unsorted(&b) == 0)
			break ;
		ft_init_cmds(&cmds, a.size + b.size); // == ac - 1 ?
		ft_cal_cmds(&a, &b, cmds);

//		// debug start
//		for (int k = 0; k < a.size + b.size; ++k)
//		{
//			printf("%5d %5d %5d %5d %5d %5d   cnt: %5d\n",cmds[k].ra, cmds[k].rra,cmds[k].rb,cmds[k].rrb,cmds[k].rr,cmds[k].rrr,cmds[k].cmd_cnt);
//		}
//		// debug end

		ft_execute_min_cnt_cmds(&a, &b, cmds, ac - 1);
		// check shortest cmd
		free(cmds);
//		ft_is_swappable(&a);
	}

	ft_final_sort(&a);
	ft_clear_stack(&a);

////	// debug
//	//print a
//	printf("stack %c\n", a.stack_name);
//	temp = a.head;
//	for (int k = 0; k < a.size; ++k)
//	{
//		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
//		temp = temp->next;
//	}
//	printf("\na stack size : %d\n\n", a.size);
//
//
//	//print b
//	printf("stack %c\n", b.stack_name);
//	temp = b.head;
//	for (int k = 0; k < b.size; ++k)
//	{
//		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
//		temp = temp->next;
//	}
//	printf("\nb stack size : %d\n\n", b.size);
//
//	printf("stack %c\n", a.stack_name);
//	temp = a.head;
//	for (int k = 0; k < a.size; ++k)
//	{
//		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
//		temp = temp->next;
//	}
//	printf("\na stack size : %d\n\n", a.size);
//
//
//	//print b
//	printf("stack %c\n", b.stack_name);
//	temp = b.head;
//	for (int k = 0; k < b.size; ++k)
//	{
//		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
//		temp = temp->next;
//	}
//	printf("\nb stack size : %d\n\n", b.size);
//	//end debug

	return (0);
}
