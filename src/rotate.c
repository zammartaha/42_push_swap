/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:26:10 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:52 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack	*stack)
{
	push_bottom(stack, pop_top(stack));
}

void	ra(t_data *data)
{
	rotate(data->a);
	if (data->print)
		ft_printf("ra\n");
}

void	rb(t_data *data)
{
	rotate(data->b);
	if (data->print)
		ft_printf("rb\n");
}

void	rr(t_data *data)
{
	rotate(data->a);
	rotate(data->b);
	if (data->print)
		ft_printf("rr\n");
}
