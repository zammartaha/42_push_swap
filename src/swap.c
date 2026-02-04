/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:10:19 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:58 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack	*stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

void	sa(t_data *data)
{
	swap(data->a);
	if (data->print)
		ft_printf("sa\n");
}

void	sb(t_data *data)
{
	swap(data->b);
	if (data->print)
		ft_printf("sb\n");
}

void	ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
	if (data->print)
		ft_printf("ss\n");
}
