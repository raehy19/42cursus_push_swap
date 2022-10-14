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

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

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
//	printf("\nstack size : %d", a.size);
//
//


	// test
	for (int k = 0; k < ac - 1; ++k)
	{
		if (a.head->is_sort == 0)
			ft_push(&a, &b);
		else
			ft_rotate(&a);
	}


//
//	// debug
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
	return (0);
}
