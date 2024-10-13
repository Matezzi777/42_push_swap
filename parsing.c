#include "push_swap.h"

static bool	double_found(char **argv, bool skip_first)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (skip_first)
			i++;
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (true);
		}
	}
	return (false);
}

//Vérifie si le nombre représenté par la string en argument tient dans un int
static bool	ft_is_valid_int(const char *param)
{
	int			i;
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	i = -1;
	if (param[0] == '-')
		sign = -1;
	if (param[0] == '-' || param[0] == '+')
		i++;
	while (param[++i])
		num = num * 10 + param[i] - '0';
	num = num * sign;
	if (num < -2147483648 || num > 2147483647)
		return (false); 
	return (true);
}

//Vérifie la validité d'un paramètre
static bool	check_param(char *param)
{
	int	i;

	i = -1;
	if (ft_strlen(param) == 1 && (param[0] == '-' || param[0] == '+'))					// Si l'argument est "-" ou "+"
		return (false);
	while (param[++i])													// Pour chaque caractère de l'argument
	{
		if (i == 0 && !(ft_isdigit(param[i]) || param[i] == '-' || param[i] == '+'))			// Si le premier char est différent de '-', '+' ou d'un chiffre
				return (false);													// Retourne 0
		else if (i > 0 && !ft_isdigit(param[i]))							// Sinon si ce n'est pas le premier char et que le char n'est pas un chiffre
				return (false);													// Retourne 0
	}
	if (!ft_is_valid_int(param))
		return (false);
	return (true);													// Retourne 1
}

//Vérifie la validité des paramètres passés
static bool	check_params_validity(char **params, bool skip_first)
{
	int	i;

	i = -1;
	if (skip_first)											// Si le flag skip_first est activé
		i++;													// Saute le premier paramètre
	while (params[++i])										// Pour chaque paramètre
		if (!check_param(params[i]))							//Si le paramètre est invalide
			return (false);												// Retourne 0
	if (double_found(params, skip_first))
		return (false);
	return (true);												//Retourne 1
}

//Vérifie la validité des arguments et remplis une stack avec les arguments (depuis une string (argc==2))
static t_node	*ft_parse_from_string(char **argv)
{
	char	**arguments;
	t_node	*stack;
	int		i;

	i = -1;
	arguments = ft_split(argv[1], ' ');						// Découpe la string en un tableau des mots séparés par ' ' ("ici la-bas maintenant" -> ["ici", "la-bas", "maintenant"])
	if (check_params_validity(arguments, false))					// Si tous les arguments sont valides sans sauter le premier argument
	{
		stack = populate_stack(arguments, false);
		while (arguments[++i])
			free(arguments[i]);
		free(arguments);
		return (stack);						// Retourne la stack rempli à partir des arguments
	}
	else													// Si tous les arguments ne sont pas valides ("a", "", "--42", "+-2")
	{
		while (arguments[++i])
			free(arguments[i]);
		ft_printf("Argument invalide détecté.\n");
		// print_error();										// Affiche un message d'erreur
		free(arguments);
		return (NULL);											// Retourne NULL
	}
}

//Vérifie la validité des arguments et remplis une stack avec les arguments (depuis un tab (argc > 2))
static t_node	*ft_parse_from_tab(char **argv)
{
	if (check_params_validity(argv, true))						// Si tous les arguments sont valides en sautant le premier argument
		return (populate_stack(argv, true));							// Retourne la stack rempli à partir des arguments
	else														// Si tous les arguments ne sont pas valides ("a", "", "--45", "+-2")
	{
		ft_printf("Argument invalide détecté.\n");
		// print_error();										// Affiche un message d'erreur
		return (NULL);											// Retourne NULL
	}
}

//Fonction d'entrée vers le parsing
t_node	*ft_parse_arguments(int argc, char **argv)
{
	if (argc < 2 || (argc == 2 && !argv[1][0]))				// Si il n'y a pas d'argument (./p_s || ./p_s "")
	{
		ft_printf("Pas d'argument.\n");
		return (NULL);
	}
	if (argc == 2)											// Si il y a 1 argument (./p_s "15 -42 67")
	{
		ft_printf("Arguments passés sous string.\n");
		return (ft_parse_from_string(argv));				// Populate la stack depuis une string (retourne NULL si param incorrect)
	}
	else													// Si il y a plus d'un argument (./p_s 15 -42 67 || ./p_s "15" "-42" "67")
	{
		ft_printf("Arguments passés sous tab.\n");
		return (ft_parse_from_tab(argv));					// Populate la stack depuis un tableau de string (retourne NULL si param incorrect)
	}
}