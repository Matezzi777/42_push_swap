/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:24:58 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/20 02:32:51 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum	e_direction
{
	NONE,
	UP,
	DOWN
}				t_direction;

typedef struct	s_stack
{
	int				value;
	int				cost;
	int				position;
	t_direction		direction;
	struct s_stack	*target;
	struct s_stack	*next;
}				t_stack;

#endif