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

void	dump_stack(t_node *stack, char name)
{
	t_node	*current;

	ft_printf("%c :\n	", name);
	current = stack;
	if (!current)
	{
		ft_printf("La stack est vide.\n");
		return ;
	}
	while(current)
	{
		ft_printf("[%d:%d] ", current->pos, current->value);
		current = current->next;
	}
	ft_printf("\n");
}

void	dump_both_stacks(t_node *a, t_node *b)
{
	dump_stack(a, 'A');
	dump_stack(b, 'B');
}

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;										// Déclaration du haut de la stack a
	// t_node	*b;

	a = ft_parse_arguments(argc, argv);				// Parsing des arguments (fait les actions nécessaires et retourne NULL en cas d'erreur)
	if (a)
		return(1);
	else
		return (0);
	// if (!a)
	// 	return (1);
	// b = NULL;
	// dump_both_stacks(a, b);

	// // == TESTS ==
	// // sa(a);
	// // rrb(b);
	// // pa(&a, &b);
	// pb(&a, &b);
	// // ===========
	
	// dump_both_stacks(a, b);
	// ft_free_stack(a);
	// ft_free_stack(b);
}