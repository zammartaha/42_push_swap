/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:08:12 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:36 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_op(t_data *data, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(data);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(data);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(data);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(data);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(data);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(data);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(data);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(data);
	else if (!ft_strncmp(op, "rra\n", 3))
		rra(data);
	else if (!ft_strncmp(op, "rrb\n", 3))
		rrb(data);
	else if (!ft_strncmp(op, "rrr\n", 3))
		rrr(data);
	else
		ft_error("not a valid operation", data);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*op;

	if (ac < 2)
		return (0);
	data.print = 0;
	data.a = create_stack();
	data.b = create_stack();
	parse(ac, av, &data);
	if (check_duplicates(data.a))
		ft_error("input has duplicate value", &data);
	op = get_next_line(0);
	while (op)
	{
		execute_op(&data, op);
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(data.a) && data.b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&data);
	return (0);
}
