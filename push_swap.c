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
	int	second_order;
}	t_node;

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_order(int val, int n)
{
	if (val < 0)
		return (n + val);
	return (val);
}


int	ft_weight(int val, int n)
{
	if (val < 0 && -val > (n / 2))
		return (n + val);
	if (val > (n / 2))
		return (n - val);
	return (val);
}

void	ft_find_target_order(t_node *list_a, int n)
{
	int	*weight_sum;
	int	temp;
	int	i;
	int	j;

	weight_sum = (int *) malloc( sizeof(int) * n);
	i = -1;
	while (++i < n)
		*(weight_sum + i) = 0;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			*(weight_sum + i) += ft_abs(ft_weight((list_a + j)->order - ft_order(j - i, n), n));
		}
	}

	// debug
	for (int k = 0; k < n; ++k)
	{
		printf("%d\n", *(weight_sum + k));
	}

	i = -1;
	temp = n * n;
	while (++i < n)
	{
		if (ft_abs(*(weight_sum + i)) < temp)
		{
			temp = ft_abs(*(weight_sum + i));
			j = i;
		}
	}
	printf("\nj: %d\n", j);
	i = -1;
	while (++i < n)
	{
		(list_a + i)->target_order = ft_order(i - j, n);
		(list_a + i)->weight = ft_weight((list_a + i)->order - (list_a + i)->target_order, n);
		(list_a + i)->absolute_weight = ft_abs((list_a + i)->weight);
	}

	i = -1;
	while (++i < n)
		(list_a + i)->second_order = 0;

	i = -1;
	while (++i < n)
	{
		if ((list_a + i)->absolute_weight > (n / 4))
		{
			(list_a + i)->second_order = -1;
		}
		else
		{
			temp = 0;
			j = -1;
			while (++j < n)
				if ((list_a + j)->absolute_weight <= (n / 4) && (list_a + j)->order <  (list_a + i)->order )
					++temp;
			(list_a + i)->second_order = temp;
		}
	}

}

int	main(void)
{
	int n = 500;
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


	ft_find_target_order(list_a, n);



	printf("data\t\torder\t\ttarget_order\tweight\t\tabsolute_weight\t\tsecond_weight\t\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t",(*(list_a + i)).data, (*(list_a + i)).order, (*(list_a + i)).target_order, (*(list_a + i)).weight, (*(list_a + i)).absolute_weight, (*(list_a + i)).second_order);
		printf("%d", (list_a + i)->order - (list_a + i)->target_order);
		if ((list_a + i)->absolute_weight > n / 4)
			printf(" \t\t\t%d ", (list_a + i)->order);
		else
			printf(" \t%d ", (list_a + i)->order);
		printf("\n");
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if ((list_a + i)->absolute_weight > (n / 4))
			++cnt;
	}
	printf("\nn : %d\ncnt : %d\n", n, cnt);
	return (0);
}
