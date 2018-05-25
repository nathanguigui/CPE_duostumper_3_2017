/*
** EPITECH PROJECT, 2018
** minicut
** File description:
** print
*/

#include "minicut.h"

int is_in_cols(int a, int *cols)
{
	for (int i = 0; cols[i] >= 0; i = i + 1)
		if (cols[i] == a)
			return (1);
	return (0);
}

void print_chars(char *line, int *cols)
{
	for (int i = 0; line[i] != '\0'; i = i + 1) {
		if (is_in_cols(i + 1, cols))
			my_putchar(line[i]);
	}
	my_putchar('\n');
}

void print_fields(char *line, int *cols, char delim)
{
	char **temp = str_to_word_array(line, delim);

	if (temp[0] == NULL) {
		my_putstr(temp[0]);
		my_putchar('\n');
		return;
	}
	if (temp[0] == NULL)
		my_putchar('\n');
	for (int i = 0; temp[i] != NULL; i = i + 1) {
		if (is_in_cols(i + 1, cols)) {
			my_putstr(temp[i]);
			(temp[i + 1] != NULL ? my_putchar(delim) : 1);
		}
	}
	my_putchar('\n');
}
