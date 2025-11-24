/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:01:09 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 12:46:13 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	create_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = value;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->back = NULL;
	}
	else
	{
		last = found_last(*stack);
		last->next = new_node;
		new_node->back = last;
	}
}

void	init_stack_a(t_stack_node **a, char **av, char **original_args)
{
	long	n;
	int		i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		if (!av[i][0])
		{
			free_errors(a, original_args);
			return ;
		}
		if (check_args(av[i]))
			free_errors(a, original_args);
		if (check_int_limits(av[i]))
			free_errors(a, original_args);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, original_args);
		if (countains_duplicate(*a, (int)n))
			free_errors(a, original_args);
		create_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_to_top(t_stack_node **stack, t_stack_node *target, char stack_name)
{
	while (*stack != target)
	{
		if (stack_name == 'a')
		{
			if (target->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (target->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
