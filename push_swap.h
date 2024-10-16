/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:11:19 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/17 01:14:07 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "my_printf/ft_printf.h"
# include <stdbool.h>

//Structure élément de stack
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				value;
	int				pos;
	int				cost;
	bool			min;
	bool			max;
	bool			direction;
}			t_node;

//parsing.c
t_node	*ft_parse_arguments(int argc, char **argv);
//parsing_utils.c
bool	double_found(char **argv, bool skip_first);
bool	ft_is_valid_int(const char *param);
//populate_stack.c
t_node	*populate_stack(char **argv, bool skip_first);
//utils.c
void	ft_print_elem_details(t_node *elem, char *name, bool jump);
void	dump_stack(t_node *stack, char name);
void	dump_both_stacks(t_node *a, t_node *b);
void	ft_free_stack(t_node *stack);
int		print_error(void);

//swap.c
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node *a, t_node *b);
//push.c
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
//rotate.c
void	ra(t_node *a);
void	rb(t_node *b);
void	rr(t_node *a, t_node *b);
//reverse_rotate.c
void	rra(t_node *a);
void	rrb(t_node *b);
void	rrr(t_node *a, t_node *b);

//sort.c
void	ft_sort(t_node *a);
//list_utils.c
int		ft_find_min(t_node *stack);
int		ft_find_max(t_node *stack);
int		ft_get_index_from_value(t_node *stack, int target);
t_node	*ft_list_head(t_node *stack);
t_node	*ft_list_last(t_node *stack);

#endif