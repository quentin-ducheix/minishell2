/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int find_nbs_compip(char *str)
{
	int nb = 1;

	for (int i = 0; str && str[i]; i++)
		if (str[i] == '|')
			nb++;
	return (nb);
}

int preli_pipe(int nbs_pips, int *ins, int *outs, int *fds)
{
	int j = 0;
	int fd[2];

	for (int i = 0; i < nbs_pips; i++) {
		outs[i] = -1;
		ins[i] = -1;
	}
	for (int i = 0; i < nbs_pips - 1; i++, j += 2) {
		pipe(fd);
		outs[i] = fd[1];
		ins[i + 1] = fd[0];
		fds[j] = fd[0];
		fds[j + 1] = fd[1];
	}
	return (0);
}

all_t *init_pipes(all_t *l_pipes, int nbs_pips, char **strpips, char **envi)
{
	int i = 0;
	int j = 0;

	for (; strpips[i]; i++);
	l_pipes->stat = malloc(sizeof(int) * nbs_pips);
	l_pipes->ins = malloc(sizeof(int) * nbs_pips);
	l_pipes->outs = malloc(sizeof(int) * nbs_pips);
	l_pipes->fds = malloc(sizeof(int) * ((nbs_pips - 1) * 2));
	l_pipes->com = malloc(sizeof(all_t*) * (i + 1));
	for (int v = 0; v < nbs_pips; v++)
		l_pipes->stat[v] = 0;
	for (; strpips[j]; j++) {
		l_pipes->com[j] = trans_str_cmd(strpips[j], envi);
		if (l_pipes->com[j] == NULL)
			return (NULL);
	}
	l_pipes->com[j] = NULL;
	return (l_pipes);
}

int look_cmds(char **strpips, all_t *l_pipes)
{
	for (int i = 0; strpips[i]; i++) {
		if (l_pipes->com[i]->path == NULL && strpips[i] &&
		strpips[i][0] != '\0' && solo_spaces(strpips[i]) == 0) {
			bled(1);
			if (l_pipes->com[i] && l_pipes->com[i]->avs)
				my_putstr(l_pipes->com[i]->avs[0]);
			my_putstr(": Command not found.\n");
			return (0);
		}
	}
	return (1);
}
