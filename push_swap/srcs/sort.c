/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:06:52 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 14:14:04 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	any_below_value(t_stack_node *stack, int value)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		if (current->value < value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	transfer_lower_quartiles(t_stack_node **a, t_stack_node **b,
		int q1, int median)
{
	while (stack_size(*a) > 3 && any_below_value(*a, q1))
	{
		if ((*a)->value < q1)
			pb(b, a, false);
		else
			ra(a, false);
	}
	while (stack_size(*a) > 3 && any_below_value(*a, median))
	{
		if ((*a)->value >= q1 && (*a)->value < median)
			pb(b, a, false);
		else
			ra(a, false);
	}
}

void	transfer_by_quartiles(t_stack_node **a, t_stack_node **b)
{
	int	q1;
	int	median;
	int	q3;

	if (stack_size(*a) <= 3)
		return ;
	q1 = find_first_quartil(*a);
	median = find_median(*a);
	q3 = find_third_quartil(*a);
	transfer_lower_quartiles(a, b, q1, median);
	while (stack_size(*a) > 3 && any_below_value(*a, q3))
	{
		if ((*a)->value >= median && (*a)->value < q3)
			pb(b, a, false);
		else
			ra(a, false);
	}
	while (stack_size(*a) > 3)
		pb(b, a, false);
}

void	ft_sort(t_stack_node **a, t_stack_node **b)
{
	if (stack_sorted(*a))
		return ;
	if (stack_size(*a) <= 3)
	{
		sort_three(a);
		return ;
	}
	transfer_by_quartiles(a, b);
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		pull_from_b_to_a(a, b);
	}
	current_index(*a);
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
