/*
** EPITECH PROJECT, 2018
** minicut
** File description:
** minicut.h
*/

#ifndef MINICUT_H_
#define MINICUT_H_

#include "my.h"
#include "get_next_line.h"


typedef struct minicut_s {
	char delim;
	char *fields;
	char *chars;
	char **file;
	int *field;
	int *charss;
} minicut_t;

minicut_t *get_minicut(int ac, char **av);
int update_struct(minicut_t *minicut);
int fill2(int *toto, char **temp, int nb, int i);
int get_nb_cols(char **temp);
int my_strcmpto(char *str1, char *str2);
char *my_strcut(char *str, char after);
int check_params(int ac, char **av, minicut_t *mini);
void print_chars(char *line, int *cols);
void print_fields(char *line, int *cols, char delim);

#endif
