/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_in_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:15:53 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 14:53:15 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;
	t_stack_node	*target_node;
	long			closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->value > b->value && cur_a->value < closest_bigger)
			{
				closest_bigger = cur_a->value;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
