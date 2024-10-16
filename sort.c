#include "push_swap.h"

bool	ft_is_list_sorted(t_node *a)
{
	t_node	*current;
	int		prev_val;

	if (!a)
		return (false);
	prev_val = a->value;
	current = a->next;
	while (current)
	{
		if (current->value < prev_val)
			return (false);
		prev_val = current->value;
		current = current->next;
	}
	return (true);
}

int	ft_list_len(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_small_sort(t_node *a)
{
	int	min;
	int	max;

	min = ft_find_min(a);
	max = ft_find_max(a);
	if (a->value == min)								//Si le min est en premier
	{
		rra(a);
		sa(a);
	}
	else if (a->value == max)							//Si le max est en premier
	{
		ra(a);
		if (!ft_is_list_sorted(a))							//Si la liste n'est pas triée
			sa(a);
	}
	else												//Si le mid est en premier
	{
		if (ft_get_index_from_value(a, max) == 1)			//Si le max est au milieu
			rra(a);
		else												//Si le max est en dernier
			sa(a);
	}
}

void	set_directions(t_node *a, t_node *b)
{
	int	len;

	len = ft_list_len(a);
	while (a)
	{
		if (a->pos <= len / 2)
			a->direction = true;
		else
			a->direction = false;
		a = a->next;
	}
	len = ft_list_len(b);
	while (b)
	{
		if (b->pos <= len / 2)
			b->direction = true;
		else
			b->direction = false;
		b = b->next;
	}
}

void	set_costs(t_node *a, t_node *b)
{
	int	len;

	len = ft_list_len(a);
	while (a)
	{
		if (a->direction)
			a->cost = a->pos;
		else
			a->cost = len - a->pos;
		a = a->next;
	}
	len = ft_list_len(b);
	while (b)
	{
		if (b->direction)
			b->cost = b->pos;
		else
			b->cost = len - b->pos;
		b = b->next;
	}
}

t_node	*ft_get_max_ptr(t_node *stack)
{
	int		max;
	t_node *max_ptr;

	max = stack->value;
	max_ptr = stack;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_ptr = stack;
		}
		stack = stack->next;
	}
	return (max_ptr);
}

/// ACTUAL
void	set_a_targets(t_node *a, t_node *b)
{
	t_node	*cursor;
	t_node	*target;

	while (a)
	{
		target = b;
		cursor = b->next;
		if (a->value < ft_find_min(b))
			target = ft_get_max_ptr(b);
		else
		{
			while (cursor)
			{
				if (cursor->value > target->value && cursor->value < a->value)
					target = cursor;
				cursor = cursor->next;
			}
		}
		a->target = target;
		a = a->next;
	}
}

int	ft_max_between(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	calculate_push_costs(t_node *a, t_node *b)
{
	set_directions(a, b);
	set_a_targets(a, b);
	set_costs(a, b);
	while (a)
	{
		if (a->direction == a->target->direction)
			a->cost = ft_max_between(a->cost, a->target->cost);
		else
			a->cost = a->cost + a->target->cost;
		a = a->next;
	}
}

t_node	*ft_find_cheapest(t_node *stack)
{
	t_node *cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	pick_move(bool direction, t_node *stack, char identifier)
{
	if (identifier == 'a' && direction)
		ra(stack);
	else if (identifier == 'a' && !direction)
		rra(stack);
	else if (identifier == 'b' && direction)
		rb(stack);
	else if (identifier == 'b' && !direction)
		rrb(stack);
}

void	prepare_for_push(t_node *a, t_node *b)
{
	t_node	*cheapest;

	cheapest = ft_find_cheapest(a);														// Trouve l'élément qui coûte le moins d'actions à être push à la bonne place en b
	while (!(a == cheapest && b==cheapest->target))										// Tant que l'élément et sa cible ne sont pas en haut de leurs stacks respectives
	{
		if (a == cheapest)																	// Si l'élément est déjà en haut de a
			pick_move(cheapest->target->direction, b, 'b');
		else if (b == cheapest->target)														// Si la cible est déjà en haut de b
			pick_move(cheapest->direction, a, 'a');
		else																				// Si l'élément et sa cible doivent se déplacer
		{
			if (cheapest->direction && cheapest->target->direction)								// Si l'élément et sa cible doivent monter
				rr(a, b);
			else if (!(cheapest->direction) && !(cheapest->target->direction))					// Si l'élément et sa cible doivent descendre
				rrr(a, b);
			else																				// Si l'élément et sa cible ne vont pas dans le même sens
			{	
				pick_move(cheapest->target->direction, b, 'b');
				pick_move(cheapest->direction, a, 'a');
			}
		}
	}
}

// void	ft_final_push(t_node **a, t_node **b)
// {
	
// }

void	ft_big_sort(t_node *a)
{
	t_node	*b;

	b = NULL;
	pb(&a, &b);														//Push 2 nombres vers b pour avoir une référence min et une référence max
	pb(&a, &b);
	while(a->next->next)											//Tant que la stack a a plus de 3 éléments
	{
		calculate_push_costs(a, b);										//Calculer le coût de push de chaque élément
		prepare_for_push(a, b);											//Faire remonter cet élément en haut et préparer la stack b à recevoir
		pb(&a, &b);														//Push l'élément
	}
	ft_small_sort(a);												//Trier les 3 éléments de la stack a
	// ft_final_push(&a, &b);											//Push tous les éléments de b vers a (en sautant l'élément mid de a)
}

void	ft_sort(t_node *a)
{
	if (ft_is_list_sorted(a))								//Si la stack est déjà triée
		return ;												//Ne fais rien
	else 													//Sinon (la stack n'est pas triée)
	{
		if (ft_list_len(a) == 2)							//Si la stack a deux éléments
			return (sa(a));										//swap()
		else if (ft_list_len(a) == 3)						//Si la stack a trois éléments
			return (ft_small_sort(a));							//small_sort()
		else												//Si la stack a plus de trois éléments
			return (ft_big_sort(a));							//big_sort()
	}
}