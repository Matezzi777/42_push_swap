#include "push_swap.h"

//Remplit une stack avec les arguments fournis
t_node	*fill_stack(char **argv)
{

}

//Vérifie la validité d'un paramètre
static int	check_param(char *param)
{
	int	i;

	i = -1;
	while (param[++i])
	{
		if (i == 0 && !(is_digit(param[i]) || param[i] == '-'))
		if (i > 0 && !is_digit(param[i]))
			return (0);
	}
}

//Vérifie la validité des paramètres passés
static int	check_params_validity(char **params)
{
	int	i;

	i = -1;
	while (params[++i])
		if (!check_param(params[i]))
			return (0);
	return (1);
}

//Vérifie la validité des arguments et remplis une stack avec les arguments (depuis une string (argc==2))
static t_node	*ft_parse_from_string(int argc, char **argv)
{
	char **arguments;

	arguments = ft_split(argv[1], ' ');
	if (check_params_validity(arguments))
		return (fill_stack(arguments));
	else
	{
		print_error();
		return (NULL);
	}
}

//Vérifie la validité des arguments et remplis une stack avec les arguments (depuis un tab (argc > 2))
static t_node	*ft_parse_from_tab(int argc, char **argv)
{
	if (check_params_validity(argv))
		return (fill_stack(argv));
	else
	{
		print_error();
		return (NULL);
	}
}

//Fonction d'entrée vers le parsing
t_node	*ft_parse_arguments(int argc, char **argv)
{
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
		return (ft_parse_from_string(argc, argv));
	else
		return (ft_parse_from_tab(argc, argv));
}