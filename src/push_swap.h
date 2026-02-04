/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:51:15 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:47:45 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	int				idx;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_stack;

typedef struct s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				print;
}	t_data;

t_stack	*create_stack(void);
t_node	*create_node(int value);
long	ft_atol(const char *str, t_data *data, char **split);
void	ft_error(char *str, t_data *data);
void	free_stack(t_stack *stack);
void	free_data(t_data *data);
void	print_stack(t_stack *stack);
void	free_split(char	**arr);
int		check_duplicates(t_stack *stack);
void	free_split_error(char **split, char *str, t_data *data);
void	parse(int ac, char **av, t_data *data);
int		is_sorted(t_stack *stack);
t_node	*get_min(t_stack *stack);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	sort(t_data *data);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
void	radix_sort(t_data *data);

#endif
