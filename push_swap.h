/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:35:29 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/11 18:35:35 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node	t_node;

struct s_node
{
	int		data;
	int		order;
	int		is_lis;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

int		ft_atoi(const char *str);
void	*ft_calloc(int count, int size);

void	ft_init_stack(t_stack *stack);
void	ft_push_stack_node(t_stack *stack, t_node *node);
void	ft_push_stack_data(t_stack *stack, int data);
t_node	*ft_pop_stack_node(t_stack *stack);
void	ft_clear_stack(t_stack *stack);

#endif
