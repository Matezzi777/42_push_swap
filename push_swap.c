#include "push_swap.h"

int	print_error(void)
{
	ft_printf("Error\n");							// Affiche l'erreur dans le terminal
	return (1);										// Renvoit 1 (utilisé pour rendre le prompt)
}

int	main(int argc, char **argv)
{
	t_node	*a;										// Déclaration du haut de la stack a
	t_node	*b;										// Déclaration du haut de la stack b

	a = NULL;										// Déférence du pointeur vers a au cas où il serait inutilisé
	b = NULL;										// Déférence du pointeur vers b au cas où il serait inutilisé
	if (argc == 1 || (argc == 2 && !argv[1][0]))	// Si aucun paramètre n'est fourni ou que le deuxième argument est une chaîne vide
		return(1);										// Rend le prompt
	if (argc == 2)									// Si il n'y a qu'un paramètre (chaîne contenant les paramètres)
		string_to_stack(&a, argv[1]);					// Mets les arguments sous forme de stack (depuis une string)
	else											// Sinon (stack passée sous liste d'int)
		tab_to_stack(&a, argv);							// Mets les arguments sous forme de stack (depuis tableau)
	if (check_stack_parsing(&a))					// Si la stack n'est pas valide (arguments invalides)
		return (print_error());							// Affiche l'erreur et rend le prompt
	sort_stack(&a, &b);								// Trie la stack
	free_stack(&a);									// Libère la mémoire utilisée
}