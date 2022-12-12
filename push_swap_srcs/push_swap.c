/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_srcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:35:23 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 17:19:32 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_cmds	*cmds;

	ft_init_stack(&a, 'a');
	ft_init_stack(&b, 'b');
	ft_parse_data(&a, ac, av);
	ft_stack_find_lis(&a);
	while (ft_count_unsorted(&a) + ft_count_unsorted(&b) > 0)
	{
		ft_is_swappable(&a);
		if (ft_count_unsorted(&a) + ft_count_unsorted(&b) == 0
			|| ft_if_three_node(&a, &b))
			break ;
		ft_init_cmds(&cmds, a.size + b.size);
		ft_cal_cmds(&a, &b, cmds);
		ft_execute_min_cnt_cmds(&a, &b, cmds, ac - 1);
		free(cmds);
	}
	ft_final_sort(&a);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
	return (0);
}
