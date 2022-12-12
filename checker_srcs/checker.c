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
		str = get_next_line(STDIN_FILENO);
	}
	return (0);
}
