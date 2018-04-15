/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

char *search(char *str, char **envi, int val)
{
	char **paths = NULL;
	char *tempo = NULL;
	int acc = 0;

	for (; envi[val] && my_strncmp("PATH=", envi[val], 5) != 0; val++);
	if (envi[val] == NULL)
		return (NULL);
	tempo = my_strdup(envi[val]);
	paths = my_str_to_word_array(tempo);
	if (paths == NULL)
		return (NULL);
	for (int j = 0; paths[j]; j++) {
		paths[j] = my_strcat(paths[j], str);
		if (paths[j] == NULL)
			return (NULL);
		acc = access(paths[j], X_OK);
		if (acc == 0)
			return (paths[j]);
	}
	return (NULL);
}

char *search_com(char *str, char **envi, int val)
{
	char *tempo = NULL;
	int acc = 0;

	if (bultis(str) == 1)
		return (str);
	else if (str && str[0] != '.' && str[0] != '/' && envi) {
		tempo = search(str, envi, val);
		return (tempo);
	} else {
		acc = access(str, X_OK);
		if (acc == 0)
			return (str);
		return (NULL);
	}
}
