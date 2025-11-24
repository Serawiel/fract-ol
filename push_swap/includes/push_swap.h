/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:48:11 by coraline          #+#    #+#             */
/*   Updated: 2025/05/07 15:09:10 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*back;
}						t_stack_node;

int						check_args(char *s);
int						countains_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a, char **args);
int						check_int_limits(char *s);
void					init_stack_a(t_stack_node **a, char **av,
							char **original_args);
void					free_split(char **split);

t_stack_node			*found_last(t_stack_node *stack);
int						stack_size(t_stack_node *stack);
int						stack_sorted(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
int						find_median(t_stack_node *stack);
int						find_first_quartil(t_stack_node *stack);
int						find_third_quartil(t_stack_node *stack);

void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);

void					current_index(t_stack_node *stack);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					move_to_top(t_stack_node **stack, t_stack_node *target,
							char stack_name);
void					ft_sort(t_stack_node **a, t_stack_node **b);
void					sort_three(t_stack_node **a);
void					pull_from_b_to_a(t_stack_node **a, t_stack_node **b);

#endif