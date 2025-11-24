/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:42:14 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 12:54:20 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack_a)
{
	t_stack_node	*current;

	current = stack_a;
	if (!current)
		return ;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*max;

	max = find_max(*a);
	if (max == *a)
		ra(a, false);
	else if ((*a)->next == max)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) == 2)
		sa(a, false);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else
		ft_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;

	a = NULL;
	b = NULL;
	args = NULL;
	if (ac < 2)
		return (1);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		init_stack_a(&a, args + 1, args);
		free_split(args);
	}
	else
		init_stack_a(&a, av + 1, NULL);
	if (!stack_sorted(a))
		sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
