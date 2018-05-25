/*
** EPITECH PROJECT, 2018
** minicut
** File description:
** Struct file
*/

#include "minicut.h"

void fill_field(int *toto, char **temp, int nb)
{
	int a = 0;

	for (int i = 0; temp[i] != NULL; i = i + 1) {
		if (!str_find(temp[i], '-'))
			toto[i + a] = my_getnbr(temp[i]);
		else {
			a = fill2(toto, temp, nb, i);
		}
	}
}

int *get_fields(char *str)
{
	char **temp = NULL;
	int nb = 0;
	int *toto;

	temp = str_to_word_array(str, ',');
	nb = get_nb_cols(temp);
	if (nb == -1)
		return (NULL);
	toto = malloc(sizeof(int) * (nb + 1));
	toto[nb] = -1;
	fill_field(toto, temp, nb);
	return (toto);
}

int update_struct(minicut_t *minicut)
{
	if (minicut == NULL)
		return (1);
	if (minicut->fields != NULL) {
		minicut->field = get_fields(minicut->fields);
		if (minicut->field == NULL)
			return (1);
	} else if (minicut->chars != NULL) {
		minicut->charss = get_fields(minicut->chars);
		if (minicut->charss == NULL)
			return (1);
	} else
		return (1);
	if (minicut->delim == '\0')
		minicut->delim = '\t';
	return (0);
}
