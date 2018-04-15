/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int moenv(char **str, char *val)
{
	int i = 0;
	int j = 0;
	int o = 0;
	char *nstr = NULL;

	for (; *str && (*str)[i] != '='; i++);
	nstr = malloc(sizeof(char) * (my_strlen(val) + (++i) + 3));
	for (int w = 0; *str && str[0][w - 1] != '='; w++, j++)
		nstr[j] = str[0][w];
	for (; val[o]; o++)
		nstr[j + o] = val[o];
	nstr[j + o] = 0;
	*str = nstr;
	return (0);
}

int commit_env(char ***envi, char *var, char *val)
{
	char **nenvi = NULL;
	char *nvar = NULL;
	int i = 0;
	int j = 0;
	int w = 0;

	cpyenv(*envi, &nenvi);
	if (nenvi == NULL)
		return (84);
	nvar = malloc(sizeof(char) * (my_strlen(val) + my_strlen(var) + 2));
	for (; var[i]; i++)
		nvar[i] = var[i];
	if (val)
		nvar[i] = '\0';
	for (;val && val[j]; j++)
		nvar[j + i] = val[j];
	nvar[j + i] = '\0';
	for (; nenvi[w]; w++);
	nenvi[w++] = nvar;
	nenvi[w] = NULL;
	return (0);
}

char *plus_egal(char *var)
{
	char *nvar = malloc(sizeof(char) * (my_strlen(var) + 2));
	int i = 0;

	for (; var[i]; i++)
		nvar[i] = var[i];
	nvar[i] = '=';
	i++;
	nvar[i] = 0;
	return (nvar);
}

int the_setenv2 (char *var, char **tmp_var, char *val, char ***envi)
{
	int tempo = 0;
	int i = 0;

	if (var == NULL) {
		bled(1);
		return (84);
	}
	for (; tmp_var && tmp_var[i] && my_strncmp(var, tmp_var[i],
	my_strlen(var)) != 0; i++);
	if (tmp_var == NULL || tmp_var[i] == NULL) {
		tempo = commit_env(envi, var, val);
		if (tempo == 84) {
			bled(1);
			return (84);
		}
	} else
		moenv(&tmp_var[i], val);
	return (0);
}

int the_setenv(char ***envi, char *var, char *val, all_t *com)
{
	char **tmp_var = *envi;
	(void)com;

	if (var == NULL) {
		the_env(tmp_var, com);
		return (0);
	}
	if (!((var[0] >= 'A' && var[0] <= 'Z') || (var[0] >= 'a' && var[0] <= 'z')
	|| (var[0] >= '0' && var[0] <= '9'))) {
		my_putstr("setenv: Variable name must contain alphanumeric ");
		my_putstr("characters.\n");
		bled(1);
		return (0);
	}
	var = plus_egal(var);
	return (the_setenv2(var, tmp_var, val, envi));
}
