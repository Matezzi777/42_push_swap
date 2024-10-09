#include "push_swap.h"

//Trie la stack passée (coeur du programme)
static void	ft_sort(t_node *a)
{
	t_node	*b;

	b = NULL;
}

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;										// Déclaration du haut de la stack a

	a = ft_parse_arguments(argc, argv);				// Parsing des arguments (fait les actions nécessaires et retourne NULL en cas d'erreur)
	if (a == NULL)
		return (1);
	ft_sort(&a);
}