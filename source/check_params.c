/*
** EPITECH PROJECT, 2017
** check_params.c
** File description:
** 
*/

#include "minicut.h"

int check_params(int ac, char **av, minicut_t *mini)
{
	int i = 1;

	while (av[i]) {
		if (my_strcmpto("-", av[i]) && i + 1 == ac)
			return (-1);
		i = i + 1;
	}
	if (mini->fields != NULL && mini->chars != NULL)
		return (-1);
	return (666);
}