/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

char *past_path(char **envi, all_t *all)
{
	char *tempo2 = look_env(envi, "OLDPWD");
	int max = my_strlen(tempo2);;
	int i = 0;
	char *npath = malloc(sizeof(char) * (max + 1));

	for (; max > 0 && tempo2[max] != '/'; max--);
	for (; i < max; i++)
		npath[i] = tempo2[i];
	if (i == 0) {
		npath[0] = '/';
		npath[1] = '\0';
	} else if (i != 0)
		npath[i] = '\0';
	the_setenv(&envi, "PWD", npath, all);
	return (npath);
}

char *full_path(char **envi, char *path)
{
	int i = 0;
	int j = 0;
	char *oldpwd = look_env(envi, "OLDPWD");
	char *npath = malloc(sizeof(char) * (my_strlen(oldpwd) +
	my_strlen(path) + 2));

	if (path && path[0] == '/')
		return (path);
	for (;oldpwd[i]; i++)
		npath[i] = oldpwd[i];
	if (npath[i - 1] == '/' && path[0] == '/')
		j++;
	if (npath[i - 1] != '/' && path[0] != '/') {
		npath[i] = '/';
		i++;
	}
	for (; path[j]; j++)
		npath[i + j] = path[j];
	npath[i + j] = '\0';
	return (npath);
}

int sauv(char *path, char **envi, all_t *all)
{
	char *pwd = look_env(envi, "PWD=");

	if (pwd)
		the_setenv(&envi, "OLDPWD", pwd, all);
	if (my_strcmp(path, "..") == 0 && look_env(envi, "OLDPWD") != NULL)
		past_path(envi, all);
	else if (look_env(envi, "OLDPWD") != NULL) {
		path = full_path(envi, path);
		the_setenv(&envi, "PWD", path, all);
	}
	return (0);
}

int my_cd2(char *path, char **envi, all_t *all)
{
	if (path) {
		sauv(path, envi, all);
		if ((chdir(path)) == -1) {
			my_putstr(path);
			bled(1);
			my_putstr(": Not a directory.\n");
			return (0);
		}
	}
	return (0);
}

int my_cd(all_t *all, char **envi)
{
	char *path = all->avs[1];
	if (path == NULL || my_strcmp(path, "~") == 0)
		path = look_env(envi, "HOME=");
	if (path && path[0] == '-' && path[1] == '\0')
		path = look_env(envi, "OLDPWD=");
	if (access(path, F_OK) == -1) {
		bled(1);
		my_putstr(path);
		my_putstr(": No such file or directory.\n");
		return (0);
	} else if (access(path, R_OK) == -1) {
		bled(1);
		my_putstr(path);
		my_putstr(": Permission denied.\n");
		return (0);
	}
	my_cd2(path, envi, all);
	return (0);
}
