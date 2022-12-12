/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:56:02 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/26 20:56:03 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node	t_node;

struct s_node
{
	int		data;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	t_node	*head;
	int		size;
	char	stack_name;
}	t_stack;

void	ft_error(int error_code);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);
int		ft_strcmp(char *s1, char *s2);

void	ft_init_stack(t_stack *stack, char stack_name);
void	ft_push_stack_node(t_stack *stack, t_node *node);
void	ft_push_stack_data(t_stack *stack, int data);
t_node	*ft_pop_stack_node(t_stack *stack);
void	ft_clear_stack(t_stack *stack);

void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
void	ft_push(t_stack *to_pop, t_stack *to_push);
void	ft_reverse_rotate_rotate(t_stack *stack1, t_stack *stack2);
void	ft_rotate_rotate(t_stack *stack1, t_stack *stack2);
void	ft_swap_swap(t_stack *stack1, t_stack *stack2);
void	ft_swap(t_stack *stack);

#endif
