/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 00:49:56 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:56 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	node->idx = -1;
	return (node);
}

t_node	*get_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	min = NULL;
	while (current)
	{
		if (current->idx == -1)
		{
			if (!min || current->value < min->value)
				min = current;
		}
		current = current->next;
	}
	return (min);
}
