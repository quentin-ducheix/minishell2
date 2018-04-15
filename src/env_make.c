/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int com_maker(all_t *all1, char **envi, all_t *all, int j)
{
	all->fname = all1->avs[j];
	all->avs = &(all1->avs[j]);
	all->path = search_com(all->avs[0], envi, 0);
	if (all->fname && all->fname[0] != '\0' &&
	solo_spaces(all->fname) == 0) {
		bled(1);
		if (all && all->avs)
			my_putstr(all->avs[0]);
		my_putstr(": Command not found.\n");
	}
	if (all->path == NULL)
		return (2);
	all->check_redir = all1->check_redir;
	all->redir = all1->redir;
	all->check_redil = all1->check_redil;
	all->redil = all1->redil;
	return (0);
}

int do_with_env(all_t *all1, char **envi, int j, int chang)
{
	all_t *all = malloc(sizeof(all_t));
	int stat = 0;
	char **tempo1 = envi;

	all->com = malloc(sizeof(all_t) * 2);
	if (all1->avs[j] == NULL)
		return (0);
	if ((com_maker(all1, envi, all, j)))
		return (0);
	all->com[1] = NULL;
	all->com[0] = all;
	all->nbs_wait = 1;
	if (chang == 1)
		tempo1 = NULL;
	main_pipe(1, all, tempo1, 0);
	term_bled(1, &stat, NULL, all);
	return (0);
}

int before_setenv2(char *str, char *left, char ***envi, all_t *all)
{
	int i = 0;
	int size_str = 0;
	int j = 0;
	char *right = NULL;

	for (; str && str[i] != '='; i++);
	i++;
	for (; str[i + size_str]; size_str++);
	right = malloc(sizeof(char) * (size_str + 1));
	for (; str[i + j]; j++)
		right[j] = str[i + j];
	right[j] = '\0';
	the_setenv(envi, left, right, all);
	return (0);
}

int before_setenv(char ***envi, char *str, all_t *all)
{
	char *left = NULL;
	int i = 0;
	int size_str = 0;

	for (; str && str[size_str] && str[size_str] != '='; size_str++);
	left = malloc(sizeof(char) * (size_str + 1));
	for (; i < size_str; i++)
		left[i] = str[i];
	left[i] = '\0';
	before_setenv2(str, left, envi, all);
	return (0);
}

char *look_env(char **envi, char *str)
{
	int i = 0;
	int j = 0;
	int size_str = my_strlen(str);

	if (size_str == 0 || envi == NULL || envi[0] == NULL)
		return (NULL);
	for (; envi && envi[i] && my_strncmp(str, envi[i], size_str) != 0; i++);
	if (envi[i] == NULL)
		return (NULL);
	for (; envi[i] && envi[i][j] && envi[i][j] != '='; j++);
	return (&(envi[i][j + 1]));
}
