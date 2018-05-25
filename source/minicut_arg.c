/*
** EPITECH PROJECT, 2017
** minicut_arg.c
** File description:
** 
*/

#include "minicut.h"

void detect_params3(minicut_t *mini, char **av, int curr)
{
	if (my_strcmpto("--delimiter", av[curr]))
		mini->delim = av[curr][my_strlen(av[curr])];
}

int detect_params2(minicut_t *mini, char **av, int curr)
{
	if (my_strcmpto("--characters", av[curr])) {
		if (!mini->chars)
			return (-1);
		mini->chars = my_strcut(av[curr], '=');
	}
	if (my_strcmpto("--fields", av[curr])) {
		if (!mini->fields)
			return (-1);
		mini->fields = my_strcut(av[curr], '=');
	}
	detect_params3(mini, av, curr);
	return (0);
}

int detect_params(minicut_t *mini, char **av, int curr)
{
	if (my_strcmp("-c", av[curr])) {
		if (mini->chars != NULL)
			return (-1);
		mini->chars = av[curr + 1];
	}
	if (my_strcmp("-f", av[curr])) {
		if (mini->fields != NULL)
			return (-1);
		mini->fields = av[curr + 1];
	}
	if (my_strcmp("-d", av[curr]) && av[curr + 1] == NULL)
		return (-1);
	(my_strcmp("-d", av[curr])) ? mini->delim = av[curr + 1][0] : 1;
	return (0);
}

minicut_t *init_minicut(void)
{
	minicut_t *result = malloc(sizeof(minicut_t));

	result->delim = '\0';
	result->fields = NULL;
	result->chars = NULL;
	return (result);
}

minicut_t *get_minicut(int ac, char **av)
{
	minicut_t *minicut = init_minicut();
	int current = 1;

	if (ac == 1)
		return (NULL);
	while (av[current]) {
		if (detect_params(minicut, av, current) == -1)
			return (NULL);
		if (detect_params2(minicut, av, current) == -1)
			return (NULL);
		if (check_params(ac, av, minicut) == -1)
			return (NULL);
		current = current + 1;
	}
	return (minicut);
}
