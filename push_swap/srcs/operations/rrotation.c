/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:26:27 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 10:42:50 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotation(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = found_last(*stack);
	last->back->next = NULL;
	last->next = *stack;
	last->back = NULL;
	*stack = last;
	last->next->back = last;
}

void	rra(t_stack_node **a, bool print)
{
	rrotation(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rrotation(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rrotation(a);
	rrotation(b);
	if (!print)
		ft_printf("rrr\n");
}
