/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:35:14 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/12 11:35:41 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *ptr, int value, int num)
{
	unsigned char	c;
	int				i;

	c = (unsigned char) value;
	i = 0;
	while (i < num)
	{
		*(((unsigned char *)ptr) + i) = c;
		++i;
	}
	return (ptr);
}

void	*ft_calloc(int count, int size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		exit(7);
	return (ft_memset(p, 0, count * size));
}
