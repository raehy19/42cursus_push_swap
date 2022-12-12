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

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

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

void	ft_init_stack(t_stack *stack, char stack_name);
void	ft_push_stack_node(t_stack *stack, t_node *node);
void	ft_push_stack_data(t_stack *stack, int data);
t_node	*ft_pop_stack_node(t_stack *stack);
void	ft_clear_stack(t_stack *stack);
