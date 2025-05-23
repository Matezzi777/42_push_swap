/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:24:58 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 01:22:26 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_direction
{
	NONE,
	UP,
	DOWN
}				t_direction;

typedef struct s_stack
{
	long			value;
	int				cost;
	int				position;
	t_direction		direction;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

//Actions
void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//Stack Utilitaries
t_stack	*create_node(long value);
t_bool	add_stack_elem(t_stack **stack, t_stack *node);
int		stack_size(t_stack **stack);
t_stack	*free_stack(t_stack **stack);

//Parsing
t_stack	*parse_arguments(int argc, char **argv);
t_stack	*get_stack_from_string(char *str);
t_bool	overflow_detected(t_stack *stack);
t_bool	double_detected(t_stack *stack);

#endif