/*
** EPITECH PROJECT, 2018
** conv
** File description:
** array
*/

#include "my.h"

int word_len2(char *str, int i, char var)
{
	int cmp = 0;

	for (; str[i] && str[i] != var; cmp++, i++);
	return (cmp);
}

int word_count2(char *str, char var)
{
	int cmp = 1;

	for (int i = 0; str[i]; i++) {
		if ((str[i] == var) && str[i + 1] != var)
			cmp++;
	}
	return (cmp);
}

char **sepa_wordarray(char *s, char var)
{
	char **bat = malloc((word_count2(s, var) + 1) * sizeof(char *));
	int i = 0;
	int j = 0;
	int k = 0;

	for (; s[i]; j++) {
		k = 0;
		for (; s[i] == var; i++);
		bat[j] = malloc((word_len2(s, i, var) + 1) * sizeof(char));
		for (; s[i] && s[i] != var; k++, i++)
			bat[j][k] = s[i];
		bat[j][k] = '\0';
		for (; s[i] == var; i++);
	}
	bat[j] = NULL;
	return (bat);
}
