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
		printf("%10d %10d %10d\n", temp->data, temp->order, temp->is_sort);
		temp = temp->next;
	}
	printf("\nstack size : %d", a.size);
	return (0);
}
