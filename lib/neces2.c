/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int line_enter(char *str)
{
	for (int i = 0; str && str[i]; i++)
		if (str[i] == '\n')
			return (1);
	return (0);
}

int redir_string(char *str, char *good_string)
{
	int i = 0;
	int j = 0;

	if (str == NULL || line_enter(str) == 0 || my_strcmp("\n", str) == 0)
		return (0);
	for (; str[i]; i++);
	i--;
	i--;
	for (; i > 0 && str[i] != '\n'; i--);
	i++;
	for (; str[i + j] && str[i + j] == good_string[j]; j++);
	if (good_string[j] == '\0')
		return (1);
	return (0);
}

char *clening_string(char *str)
{
	int i = 0;

	for (; str[i]; i++);
	i--;
	i--;
	for (; str[i] != '\n'; i--);
	i++;
	for (; str[i]; i++)
		str[i] = '\0';
	return (str);
}

char *my_strdup2(char *str, char *str2)
{
	int j = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] != ':') {
			str2[j] = str[i];
			j++;
		} else {
			str2[j] = '/';
			j++;
			str2[j] = ' ';
			j++;
		}
	}
	str2[j] = '/';
	str2[j + 1] = '\0';
	return (str2);
}

char *my_strdup(char *str)
{
	int size = 0;
	char *str2 = NULL;
	int nb_two_points = 0;

	while (str[size])
		if (str[size++] == ':')
			nb_two_points = nb_two_points + 1;
	str2 = malloc(sizeof(char) * (size + 2 + nb_two_points));
	str2 = my_strdup2(str, str2);
	return (str2);
}
