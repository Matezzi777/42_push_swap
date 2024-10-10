#include "push_swap.h"

void	ft_free_stack(t_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}

//	Print le message d'erreur
//		Return : 1
int	print_error(void)
{
	ft_printf("Error\n");							// Affiche l'erreur dans le terminal
	return (1);										// Renvoit 1 (utilisé pour rendre le prompt)
}