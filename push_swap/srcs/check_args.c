/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:01:49 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 12:43:53 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char *s)
{
	int	i;

	i = 0;
	if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	countains_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		current->value = 0;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a, char **args)
{
	free_stack(a);
	if (args)
		free_split(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_int_limits(char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		len++;
		i++;
	}
	if (len > 10)
		return (1);
	return (0);
}
