/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int the_unsetenv(char ***envi, all_t *com)
{
	int i = 0;

	if (com->avs[1] == NULL) {
		bled(1);
		my_putstr("unsetenv: Too few arguments.\n");
		return (0);
	}
	if (com->avs[1] == NULL || my_strlen(com->avs[1]) == 0
	|| my_strchr(com->avs[1], '=') != NULL) {
		bled(1);
		my_putstr("unsetenv: Too few arguments.\n");
		return (0);
	}
	for (; (*envi) && (*envi)[i] && my_strncmp(com->avs[1], (*envi)[i],
	my_strlen(com->avs[1])) != 0; i++);
	if ((*envi)[i] == NULL)
		return (0);
	for (; (*envi)[i]; i++)
		(*envi)[i] = (*envi)[i + 1];
	(*envi)[i] = NULL;
	return (0);
}
