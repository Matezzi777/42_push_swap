#include "push_swap.h"

/*
			ETAT ACTUEL
	- Parsing :
		- Implémenter valeurs maximales et minimales (INT_MAX et INT_MIN) comme des erreurs (ft_check_param(char *param))
		- Gérer les leaks causés par ft_split() dans parse_from_string().
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
		return (0);
	ft_printf("a : %p\n", &a);
	cursor = a;
	while (cursor != NULL)
	{
		ft_printf("%d (%d)\n", cursor->value, cursor->pos);
		cursor = cursor->next;
	}
	// if (a == NULL)
		// return (1);
	// ft_sort(&a);
	ft_free_stack(a);
	ft_printf("\n");
}