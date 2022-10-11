
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node t_node;

typedef struct s_node
{
	int	data;
	int	order;
	t_node	*prev;
	t_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	**head;

} t_stack;

#endif
