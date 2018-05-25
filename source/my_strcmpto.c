/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "../include/minicut.h"

int my_strcmpto(char *str1, char *str2)
{
	int i = 0;
	int k = my_strlen(str1) - 1;

	if (str1 == NULL && str2 == NULL)
		return (1);
	else if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[i] != '\0' && str2[i] != '\0' && i < k) {
		if (str1[i] != str2[i])
			return (0);
		i = i + 1;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

char *my_strcut(char *str, char after)
{
	char *result;
	int start = 0;
	int size = my_strlen(str);
	int i = 0;

	while (str[start] != after)
		start = start + 1;
	start = start + 1;
	result = malloc(sizeof(char) * size - start + 1);
	while (str[start + i]) {
		result[i] = str[start + i];
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}