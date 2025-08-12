/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:11:03 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 18:21:08 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	long			value;
	int				index;
	int				cost;
	t_bool			above_median;
	t_bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

// Parsing
t_stack	*parse_arguments(int argc, char **argv);
t_stack	*get_stack_from_string(char *str);
t_bool	overflow_detected(t_stack *stack, int argc, char **argv);
t_bool	double_detected(t_stack *stack);
// Stack Memory
t_stack	*create_node(long value);
t_bool	add_stack_elem(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
// Stack Utils
t_bool	is_sort(t_stack **stack);
int		stack_size(t_stack **stack);
t_stack	*stack_max(t_stack **stack);
t_stack	*stack_min(t_stack **stack);
t_stack	*stack_cheapest(t_stack **stack);
void	min_on_top(t_stack **stack);
void	set_cheapest(t_stack **stack);
// Sort
void	small_sort(t_stack **a);
void	sort(t_stack **a);
void	update_a(t_stack **a, t_stack **b);
void	update_b(t_stack **a, t_stack **b);
void	update_index(t_stack **stack);
void	update_costs(t_stack **a, t_stack **b);
void	update_targets_a(t_stack **a, t_stack **b);
void	update_targets_b(t_stack **a, t_stack **b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

// Operations
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif