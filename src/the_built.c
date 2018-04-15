/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int bultis(char *str)
{
	if (my_strcmp(str, "cd") == 0)
		return (1);
	if (my_strcmp(str, "unsetenv") == 0)
		return (1);
	if (my_strcmp(str, "exit") == 0)
		return (1);
	if (my_strcmp(str, "env") == 0)
		return (1);
	if (my_strcmp(str, "setenv") == 0)
		return (1);
	return (0);
}

int built_it2(all_t *com, int i, int tempo, char **envi)
{
	if (my_strcmp(com->fname, "cd") == 0) {
		for (; com->avs[i]; i++);
		if (i > 1 && i > 2) {
			my_putstr("cd: Too many arguments.\n");
			bled(1);
			return (0);
		}
		tempo = my_cd(com, envi);
		return (tempo);
	}
	if (my_strcmp(com->fname, "exit") == 0) {
		tempo = for_exit(com->avs[1]);
		return (tempo);
	}
	return (tempo);
}

int built_it(all_t *com, all_t *pip, char **envi)
{
	int i = 0;
	int tempo = 0;

	pip->nbs_wait--;
	if (my_strcmp(com->fname, "setenv") == 0) {
		tempo = the_setenv(&envi, com->avs[1], com->avs[2], com);
		return (tempo);
	}
	if (my_strcmp(com->fname, "unsetenv") == 0) {
		tempo = the_unsetenv(&envi, com);
		return (tempo);
	}
	if (my_strcmp(com->fname, "env") == 0) {
		tempo = the_env(envi, com);
		return (tempo);
	}
	if (my_strcmp(com->fname, "cd") == 0 ||
	my_strcmp(com->fname, "exit") == 0)
		return (built_it2(com, i, tempo, envi));
	return (0);
}

int for_exit(char *exiter)
{
	int exited = 0;

	if (exiter == NULL || my_strcmp(exiter, "0") == 0) {
		my_putstr("exit\n");
		exit (0);
	}
	for (int i = 0; exiter && exiter[i]; i++) {
		if (!((exiter[i] >= '0' && exiter[i] <= '9')) &&
		exiter[i] != '-') {
			bled(1);
			my_putstr("exit: Expression Syntax.\n");
			return (1);
		}
	}
	my_putstr("exit\n");
	exited = my_get_nbr(exiter);
	bled(my_get_nbr(exiter));
	exit (exited);
}
