/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 00:02:10 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:39 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(int ac, char **av, t_data *data)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split[0])
			free_split_error(split, "empty string", data);
		j = 0;
		while (split[j])
		{
			push_bottom(data->a, create_node(ft_atol(split[j], data, split)));
			j++;
		}
		free_split(split);
		i++;
	}
}

long	ft_atol(const char *str, t_data *data, char **split)
{
	int		i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] != '\0' && str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			free_split_error(split, "value is not integer", data);
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
			free_split_error(split, "value out of range", data);
		i++;
	}
	return (res * sign);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	if (stack->size == 0)
		return (0);
	i = stack->top;
	j = stack->top->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		ft_printf("idx: %d value:%d\n", current->idx, current->value);
		current = current->next;
	}
}
