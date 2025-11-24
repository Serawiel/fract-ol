/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:47:04 by cprot             #+#    #+#             */
/*   Updated: 2025/05/07 10:39:30 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortab(int *tab, int size)
{
	int	i;
	int	swapped;
	int	temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	*create_and_sort_tab(t_stack_node *stack)
{
	int				*tab;
	int				i;
	t_stack_node	*cur;
	int				size;

	i = 0;
	size = stack_size(stack);
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (0);
	cur = stack;
	while (cur)
	{
		tab[i++] = cur->value;
		cur = cur->next;
	}
	ft_sortab(tab, size);
	return (tab);
}

int	find_median(t_stack_node *stack)
{
	int	*tab;
	int	size;
	int	median;

	if (!stack)
		return (0);
	size = stack_size(stack);
	if (size == 0)
		return (0);
	tab = create_and_sort_tab(stack);
	if (!tab)
		return (0);
	median = tab[size / 2];
	free(tab);
	return (median);
}

int	find_first_quartil(t_stack_node *stack)
{
	int	*tab;
	int	size;
	int	q;

	size = stack_size(stack);
	tab = create_and_sort_tab(stack);
	if (!tab)
		return (0);
	q = tab[size / 4];
	free(tab);
	return (q);
}

int	find_third_quartil(t_stack_node *stack)
{
	int	*tab;
	int	size;
	int	q;

	size = stack_size(stack);
	tab = create_and_sort_tab(stack);
	if (!tab)
		return (0);
	q = tab[(size * 3) / 4];
	free(tab);
	return (q);
}
