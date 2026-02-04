/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:13:47 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:44 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (0);
	data.print = 1;
	data.a = create_stack();
	data.b = create_stack();
	parse(ac, av, &data);
	if (check_duplicates(data.a))
		ft_error("input has duplicate value", &data);
	if (!is_sorted(data.a))
	{
		sort(&data);
	}
	free_data(&data);
	return (0);
}
