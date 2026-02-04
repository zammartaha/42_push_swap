/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 01:09:18 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:50 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_stack(t_stack *a)
{
	int		i;
	t_node	*min;

	i = 0;
	while (i < a->size)
	{
		min = get_min(a);
		if (min)
			min->idx = i;
		else
			break ;
		i++;
	}
}

static int	get_max_bits(t_stack *a)
{
	int	bits;
	int	max;

	max = a->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_data *data)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	index_stack(data->a);
	bits = get_max_bits(data->a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		size = data->a->size;
		while (j < size)
		{
			if (((data->a->top->idx >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
			j++;
		}
		while (data->b->size > 0)
			pa(data);
		i++;
	}
}
