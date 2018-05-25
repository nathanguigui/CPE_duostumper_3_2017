/*
** EPITECH PROJECT, 2018
** stumper2
** File description:
** tools
*/

#include "minicut.h"

int get_nb(char *temp)
{
	int temp1 = my_getnbr(temp);
	int temp2;

	if (temp[my_nblen(temp1)] != '-' ||
		!is_number(&(temp[my_nblen(temp1) + 1])))
		return (-1);
	temp2 = my_getnbr(&(temp[my_nblen(temp1) + 1]));
	if (temp2 - temp1 < 0) {
		if (temp[my_strlen(temp) - 1] != '-')
			return (-1);
		else
			return (-2);
	}
	return (temp2 - temp1 + 1);
}

int toto(char **temp, int i)
{
	int temp1 = get_nb(temp[i]);

	if (temp1 == -1)
		return (-1);
	else if (temp1 == -2) {
		if (temp[i + 1] == NULL)
			return (1);
		else
			return (-1);
	} else
		return (temp1);
}

int get_nb_cols(char **temp)
{
	int nb = 0;
	int temp1;

	for (int i = 0; temp[i] != NULL && nb != -1; i = i + 1) {
		if (!str_find(temp[i], '-') && !is_number(temp[i]))
			return (-1);
		else if (str_find(temp[i], '-')) {
			temp1 = toto(temp, i);
			nb = (temp1 == -1 ? -1 : nb + temp1);
		} else
			nb = nb + 1;
	}
	return (nb);
}

int fill2(int *toto, char **temp, int nb, int i)
{
	int temp1 = my_getnbr(temp[i]);
	int temp2 = my_getnbr(&(temp[i][my_nblen(temp1) + 1]));
	static int a = 0;
	int b;

	if (temp[i][my_strlen(temp[i]) - 1] == '-') {
		toto[nb] = -2;
		toto[i] = -2;
		return (0);
	}
	for (b = 0; temp1 + b <= temp2; b = b + 1) {
		toto[i + b + a] = temp1 + b;
	}
	a = b - 1;
	return (b - 1);
}
