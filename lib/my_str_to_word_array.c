/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int word_len(char *str, int i)
{
	int cmp = 0;

	for (; str[i] && str[i] != ' ' && str[i] != '\t'; cmp++, i++);
	return (cmp);
}

int word_count(char *str)
{
	int cmp = 1;

	for (int i = 0; str[i]; i++) {
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' ' && str[i + 1] != '\t')
			cmp++;
	}
	return (cmp);
}

char **my_str_to_word_array(char *s)
{
	char **tab = malloc((word_count(s) + 1) * sizeof(char *));;
	int i = 0;
	int j = 0;
	int k = 0;

	for (; s[i]; j++) {
		k = 0;
		for (; s[i] == ' ' || s[i] == '\t'; i++);
		tab[j] = malloc((word_len(s, i) + 1) * sizeof(char));
		for (; s[i] && s[i] != ' ' && s[i] != '\t'; k++, i++)
			tab[j][k] = s[i];
		tab[j][k] = '\0';
		for (; s[i] == ' ' || s[i] == '\t'; i++);
	}
		tab[j] = NULL;
		return (tab);
}
