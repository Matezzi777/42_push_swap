#include "push_swap.h"

void	ft_free_stack(t_node *stack)
{
	t_node *current;
	t_node *next_node;

	current = stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

//	Print le message d'erreur
//		Return : 1
int	print_error(void)
{
	ft_printf("Error\n");							// Affiche l'erreur dans le terminal
	return (1);										// Renvoit 1 (utilisé pour rendre le prompt)
}