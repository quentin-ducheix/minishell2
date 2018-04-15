/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int bled(int add)
{
	static int i = 0;

	if (add == -99)
		return(i);
	i = add;
	return (i);
}

int checker_redi(char *redi)
{
	for (int i = 0; redi[i]; i++) {
		if ((redi[i] == '>' && redi[i + 1] == '>' && redi[i + 2] == '>')
		|| (redi[i] == '>' && redi[i + 1] == ' ' &&
		redi[i + 2] == '>')) {
			my_putstr("Missing name for redirect.\n");
			return (2);
		}
		if ((redi[i] == '<' && redi[i + 1] == '<' && redi[i + 2] == '<')
		|| (redi[i] == '<' && redi[i + 1] == ' ' &&
		redi[i + 2] == '<')) {
			my_putstr("Missing name for redirect.\n");
			return (2);
		}
		if ((redi[i] == '>' || redi[i] == '<')
		&& (redi[i + 1] == '|' || redi[i + 1] == '\0' ||
		(redi[i + 1] == ' ' && (redi[i + 2] == '\0' ||
		redi[i + 2] == '|')))) {
			my_putstr("Missing name for redirect.\n");
			return (2);
		}
		if ((redi[i] == '>' && redi[i + 1] == '<')
		|| (redi[i] == '<' && redi[i + 1] == '>')) {
			my_putstr("Missing name for redirect.\n");
			return (2);
		}
	}
	return (0);
}

int checkit(char *check)
{
	int i = checker_redi(check);
	int j = 0;

	if (i == 2)
		return (2);
	i = 0;
	if (check[0] == '|') {
		my_putstr("Invalid null command.\n");
		return (2);
	}
	for (; check[i]; i++) {
		if ((check[i] == ';' || check[i] == '|')
		&& ((check[i + 1] == ';' || check[i + 1] == '|') ||
		(check[i + 1] == ' '
		&& (check[i + 2] == ';' || check[i + 2] == '|')))) {
			my_putstr("Invalid null command.\n");
			return (2);
		}
	}
	j = i;
	for (; check[j - 1] == ' '; j--);
	if (check[j - 1] == '|') {
		my_putstr("Invalid null command.\n");
		return (2);
	}
	return (0);
}
