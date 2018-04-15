/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int is_env(char *str)
{
	if (my_strcmp(str, "setenv") == 0)
		return (1);
	if (my_strcmp(str, "env") == 0)
		return (1);
	if (my_strcmp(str, "-i") == 0)
		return (1);
	if (my_strchr(str, '=') != NULL)
		return (1);
	return (0);
}

char **save_envi(char **envi)
{
	char **nenvi;
	int len = 0;
	int j = 0;

	if (envi == NULL)
		return (NULL);
	for (; envi[len]; len++);
	nenvi = malloc(sizeof(char*) * len + 1);
	for (; envi[j]; j++)
		nenvi[j] = envi[j];
	nenvi[j] = NULL;
	return (nenvi);
}

int do_it_env(char **envi, all_t *options, all_t *all, int j)
{
	int tempo = 0;

	for (int i = 0; all && all->avs[i] && i < j; i++)
		if (my_strchr(all->avs[i], '=') != NULL)
			before_setenv(&envi, all->avs[i], all);
	if (all->avs[j] == NULL && options->i == 1)
		tempo = play_env(NULL, all);
	else if (all->avs[j] == NULL && options->i != 1)
		tempo = play_env(envi, all);
	tempo = do_with_env(all, envi, j, options->i);
	if (all->avs[j] != NULL)
		tempo = 0;
	return (tempo);
}

int the_env(char **envi, all_t *all)
{
	all_t *opt_env = malloc(sizeof(all_t));
	char **nenvi = NULL;
	int tempo = 0;
	int j = 0;

	if (all == NULL)
		return (0);
	opt_env->i = 0;
	opt_env->u = 0;
	opt_env->zeros = 0;
	for(; all && all->avs[j] && is_env(all->avs[j]) == 1; j++)
		if (my_strcmp(all->avs[j], "-i") == 0)
			opt_env->i = 1;
	if (j == 0)
		return (0);
	nenvi = save_envi(envi);
	if (nenvi == NULL)
		return (84);
	tempo = do_it_env(nenvi, opt_env, all, j);
	return (tempo);
}
