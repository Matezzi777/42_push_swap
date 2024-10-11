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

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;										// Déclaration du haut de la stack a
	t_node	*cursor;

	a = ft_parse_arguments(argc, argv);				// Parsing des arguments (fait les actions nécessaires et retourne NULL en cas d'erreur)
	if (!a)
		return (1);
	cursor = a;
	while (cursor != NULL)
	{
		ft_printf("	%d : %d\n", cursor->pos, cursor->value);
		cursor = cursor->next;
	}
	ft_sort(&a);
	ft_free_stack(a);
}