/*
** EPITECH PROJECT, 2018
** minicut
** File description:
** Main file
*/

#include "minicut.h"

void my_minicut(minicut_t *minicut)
{
	if (minicut->chars != NULL) {
		for (int i = 0; minicut->file[i]; i = i + 1)
			print_chars(minicut->file[i], minicut->charss);
	} else if (minicut->fields != NULL) {
		for (int i = 0; minicut->file[i]; i = i + 1)
			print_fields(minicut->file[i], minicut->field,
			minicut->delim);
	}
}

char **get_file(void)
{
	char **res = NULL;
	char *line = "";

	while (line != NULL) {
		line = get_next_line(0);
		realloc_tab((void ***)&res, line);
	}
	return (res);
}

int main(int ac, char **av)
{
	minicut_t *minicut = get_minicut(ac, av);

	if (minicut == NULL || update_struct(minicut) == 1)
		return (84);
	minicut->file = get_file();
	if (minicut->file == NULL)
		return (0);
	my_minicut(minicut);
	return (0);
}
