/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:41:28 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:41 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->size == 0)
		return (NULL);
	node = stack->bottom;
	stack->bottom = stack->bottom->prev;
	if (stack->bottom)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	stack->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
