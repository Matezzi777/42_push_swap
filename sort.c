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

// void	ft_big_sort(t_node *a)
// {

// }

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
			return ;
			// return (ft_big_sort(a));							//big_sort()
	}
}