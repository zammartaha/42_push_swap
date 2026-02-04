/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:45:58 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:47 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->prev = node;
		node->next = stack->top;
		stack->top = node;
	}
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
	stack->size++;
}

void	pa(t_data *data)
{
	push_top(data->a, pop_top(data->b));
	if (data->print)
		ft_printf("pa\n");
}

void	pb(t_data *data)
{
	push_top(data->b, pop_top(data->a));
	if (data->print)
		ft_printf("pb\n");
}
