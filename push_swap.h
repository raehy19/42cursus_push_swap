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
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	t_node	**head;
	int		size;
}	t_stack;

#endif
