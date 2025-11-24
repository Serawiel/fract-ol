/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:05:42 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 15:05:41 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost(t_stack_node *a, t_stack_node *b,
	t_stack_node *node_a, t_stack_node *node_b)
{
	int	cost_a;
	int	cost_b;
	int	total_cost;

	if (node_a->above_median)
		cost_a = node_a->index;
	else
		cost_a = stack_size(a) - node_a->index;
	if (node_b->above_median)
		cost_b = node_b->index;
	else
		cost_b = stack_size(b) - node_b->index;
	if ((node_a->above_median && node_b->above_median)
		|| (!node_a->above_median && !node_b->above_median))
	{
		total_cost = cost_a;
		if (cost_b > cost_a)
			total_cost = cost_b;
	}
	else
		total_cost = cost_a + cost_b;
	return (total_cost);
}

static void	apply_rotations(t_stack_node **a, t_stack_node **b,
		t_stack_node *node_a, t_stack_node *node_b)
{
	if (node_a->above_median && node_b->above_median)
	{
		while (*a != node_a && *b != node_b)
			rr(a, b, false);
		while (*a != node_a)
			ra(a, false);
		while (*b != node_b)
			rb(b, false);
	}
	else if (!node_a->above_median && !node_b->above_median)
	{
		while (*a != node_a && *b != node_b)
			rrr(a, b, false);
		while (*a != node_a)
			rra(a, false);
		while (*b != node_b)
			rrb(b, false);
	}
	else
	{
		move_to_top(a, node_a, 'a');
		move_to_top(b, node_b, 'b');
	}
}

static t_stack_node	*find_best_node_b(t_stack_node *a, t_stack_node *b,
		t_stack_node **best_target_a)
{
	t_stack_node	*best_b;
	t_stack_node	*current;
	int				min_cost;
	int				current_cost;

	best_b = b;
	min_cost = INT_MAX;
	current = b;
	while (current)
	{
		current_cost = calculate_cost(a, b, current->target_node, current);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best_b = current;
			*best_target_a = current->target_node;
		}
		current = current->next;
	}
	return (best_b);
}

void	pull_from_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best_b;
	t_stack_node	*best_target_a;

	best_target_a = NULL;
	best_b = find_best_node_b(*a, *b, &best_target_a);
	apply_rotations(a, b, best_target_a, best_b);
	pa(a, b, false);
}
