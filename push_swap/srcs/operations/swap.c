/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:23:32 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 10:46:14 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->back->back = *head;
	(*head)->back->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->back = (*head)->back;
	(*head)->next = (*head)->back;
	(*head)->back = NULL;
}

void	sa(t_stack_node **a, bool print)
{
	swap_stack(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap_stack(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap_stack(a);
	swap_stack(b);
	if (!print)
		ft_printf("ss\n");
}
