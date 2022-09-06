/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:15:33 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/06 15:15:34 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_node
{
	int	data;
	int	order;
	int	target_order;
	int	weight;
	int	absolute_weight;
}	t_node;

int	ft_order(int val, int n)
{
	if (val < 0)
		return (n + val);
	return (val);
}


int	ft_weight(int val, int n)
{
	if (val > (n / 2))
		return (n - val);
	return (val);
}

void	ft_find_target_order(t_node *list_a, int n)
{
	int	*weight_sum;
	int i;
	int j;

	weight_sum = (int *) malloc( sizeof(int) * n)
	i = -1;
	while (++i < n)
		*(weight_sum + i) = 0;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			(*(list_a + j)).target_order = ft_order(j - i, n);
			*(weight_sum + i) += ft_weight((*(list_a + j)).order - (*(list_a + j)).target_order, n);
		}
	}
}

int	main(void)
{
	int n = 20;
	t_node *list_a;
	int temp;


	//rand
	srand(time(NULL));
	list_a = (t_node *) malloc(sizeof(t_node) * n);
	for (int i = 0; i < n; ++i)
	{
		(*(list_a + i)).data = rand() % 100000;
	}


	for (int i = 0; i < n; ++i)
	{
		temp = 0;
		for (int j = 0; j < n; ++j)
			if ((*(list_a + i)).data > (*(list_a + j)).data)
				++temp;
		(*(list_a + i)).order = temp;
	}




	printf("data\t\torder\t\ttarget_order\tweight\t\tabsolute_weight\t\t\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n", (*(list_a + i)).data, (*(list_a + i)).order, (*(list_a + i)).target_order, (*(list_a + i)).weight, (*(list_a + i)).absolute_weight);
	}
	return (0);
}
