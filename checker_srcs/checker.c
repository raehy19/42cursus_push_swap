/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_srcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:51:28 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:19:26 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


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
			temp = temp->next;
		}
		current = current->next;
	}
}

void	execute_cmd(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_swap(a);
	if (ft_strcmp(str, "sb\n") == 0)
		ft_swap(b);
	if (ft_strcmp(str, "ss\n") == 0)
		ft_swap_swap(a, b);
	if (ft_strcmp(str, "pa\n") == 0)
		ft_push(b, a);
	if (ft_strcmp(str, "pb\n") == 0)
		ft_push(a, a);
	if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate(a);
	if (ft_strcmp(str, "rr\n") == 0)
		ft_rotate_rotate(a, b);
	if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate(b);
	if (ft_strcmp(str, "rra\n") == 0)
		ft_reverse_rotate(a);
	if (ft_strcmp(str, "rrb\n") == 0)
		ft_reverse_rotate(b);
	if (ft_strcmp(str, "rrr\n") == 0)
		ft_reverse_rotate_rotate(a, b);
	else
		ft_error(10);
}

int	ft_check_stacks(t_stack *a, t_stack *b)
{
	int		i;
	int		prev_data;
	t_node	*temp;

	if (b->size != 0)
		return (-1);
	i = 0;
	prev_data = a->head->data;
	temp = a->head->next;
	while (++i < a->size)
	{
		if (temp->data < prev_data)
			return (-1);
		prev_data = temp->data;
		temp = temp->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*str;

	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	ft_parse_data(&a, ac, av);
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		execute_cmd(str, &a, &b);
		str = get_next_line(STDIN_FILENO);
	}
	if (ft_check_stacks(&a, &b) == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	return (0);
}
