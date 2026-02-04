/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:45:42 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:54 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack	*stack)
{
	push_top(stack, pop_bottom(stack));
}

void	rra(t_data *data)
{
	rrotate(data->a);
	if (data->print)
		ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	rrotate(data->b);
	if (data->print)
		ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	rrotate(data->a);
	rrotate(data->b);
	if (data->print)
		ft_printf("rrr\n");
}
