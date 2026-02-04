/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:21:21 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:55 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	sort3(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->top->value;
	b = data->a->top->next->value;
	c = data->a->bottom->value;
	if (is_sorted(data->a))
		return ;
	if (a > b)
	{
		if (a > c)
			ra(data);
		if (a < c || b > c)
			sa(data);
	}
	if (a < b)
	{
		rra(data);
		if (a < c)
			sa(data);
	}
}

static void	sort4(t_data *data)
{
	t_node	*min;

	min = get_min(data->a);
	if (min == data->a->top || min == data->a->top->next)
	{
		while (data->a->top != min)
			ra(data);
	}
	else
	{
		while (data->a->top != min)
			rra(data);
	}
	pb(data);
	sort3(data);
	pa(data);
}

static void	sort5(t_data *data)
{
	t_node	*min;

	min = get_min(data->a);
	if (min == data->a->top || min == data->a->top->next)
	{
		while (data->a->top != min)
			ra(data);
	}
	else
	{
		while (data->a->top != min)
			rra(data);
	}
	pb(data);
	sort4(data);
	pa(data);
}

void	sort(t_data *data)
{
	if (data->a->size == 2)
		sa(data);
	if (data->a->size == 3)
		sort3(data);
	if (data->a->size == 4)
		sort4(data);
	if (data->a->size == 5)
		sort5(data);
	if (data->a->size > 5)
		radix_sort(data);
}
