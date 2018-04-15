/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

char *the_realloc(char *dest, char *src)
{
	char *new_str = malloc(sizeof(char) * (my_strlen(dest) +
	my_strlen(src) + 2));
	int x = 0;
	int y = 0;

	for (; dest && dest[x]; x++)
		new_str[x] = dest[x];
	if (dest)
		new_str[x++] = '\n';
	for (; src && src[y]; y++)
		new_str[x + y] = src[y];
	new_str[x + y] = '\0';
	return (new_str);
}

int solo_spaces(char *str)
{
	for (int i = 0; str && str[i]; i++)
		if (str[i] != ' ')
			return (0);
	return (1);
}
