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

void	dump_stacks(t_node *a, t_node *b)
{
	ft_printf("\n    A --- B\n");
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("%d : %d --- %d\n", a->pos, a->value, b->value);
			a = a->next;
			b = b->next;
		}
		else if (a)
		{
			ft_printf("%d : %d\n", a->pos, a->value);
			a = a->next;
		}
		else
		{
			ft_printf("%d :   --- %d\n", b->pos, b->value);
			b = b->next;
		}
	}
	ft_printf("\n");
}

void	dump_stack(t_node *stack)
{
	while(stack)
	{
		ft_printf("	%d : %d\n", stack->pos, stack->value);
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
	dump_stacks(a, b);
	ra(a);
	dump_stacks(a, b);
	pa(a, b);
	dump_stacks(a, b);
	// ft_sort(&a);
	ft_free_stack(a);
	ft_free_stack(b);
}