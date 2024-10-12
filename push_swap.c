#include "push_swap.h"

/*
			ETAT ACTUEL
	- Parsing	:	OK
	- Tri		:	En cours...
*/

//Trie la stack passée (coeur du programme)
// static void	ft_sort(t_node *a)
// {
// 	t_node	*b;

// 	b = NULL;
// }

void	dump_stack(t_node *stack)
{
	while(stack)
	{
		ft_printf("%d : %d\n", stack->pos, stack->value);
		stack = stack->next;
	}
}

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;										// Déclaration du haut de la stack a
	t_node	*b;

	a = ft_parse_arguments(argc, argv);				// Parsing des arguments (fait les actions nécessaires et retourne NULL en cas d'erreur)
	if (!a)
		return (1);
	b = ft_parse_arguments(argc, argv);
	ft_printf("\nBEFORE :\n* a\n");
	dump_stack(a);
	ft_printf("* b\n");
	dump_stack(b);
	// swap(a);
	// swap(b);
	ss(a, b);
	ft_printf("\nAFTER :\n* a\n");
	dump_stack(a);
	ft_printf("* b\n");
	dump_stack(b);
	// ft_sort(&a);
	ft_free_stack(a);
	ft_free_stack(b);
}