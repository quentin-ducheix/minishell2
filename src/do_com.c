/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int main_pipe2 (all_t *l_pip, int *nb_com_pipe, int *i, char ***envi,
	int *is_redi)
{
	do_redir_it(l_pip, *i, *is_redi);
	for (int j = 0; j < 2 * (*nb_com_pipe - 1); j++)
		close(l_pip->fds[j]);
	if ((execve(l_pip->com[*i]->path, l_pip->com[*i]->avs,
	*envi)) == -1) {
		bled(1);
		exit(1);
	}
	return (0);
}

int main_pipe(int nb_com_pipe, all_t *l_pip, char **envi, int is_redi)
{
	pid_t pid;

	for (int i = 0; i < nb_com_pipe; i++) {
		if (bultis(l_pip->com[i]->fname) == 1
		&& (built_it(l_pip->com[i], l_pip, envi) != 0))
			return (0);
		else if ((bultis(l_pip->com[i]->fname) == 0) &&
		(pid = fork()) == 0) {
			main_pipe2(l_pip, &nb_com_pipe, &i, &envi, &is_redi);
		}
	}
	return (0);
}

void term_bled2(int stat)
{
	if (WTERMSIG(stat) == 11) {
		bled(139);
		my_putstr("Segmentation fault");
		if (WCOREDUMP(stat))
			my_putstr(" (core dumped)\n");
		else
			my_putchar('\n');
	} else if (WTERMSIG(stat) == 8) {
		bled(136);
		my_putstr("Floating exception");
		if (WCOREDUMP(stat))
			my_putstr(" (core dumped)\n");
		else
			my_putchar('\n');
	} else {
		bled(WEXITSTATUS(stat));
	}
}

void term_bled(int nbs, int *stat, int *fds, all_t *all)
{
	int tempo = nbs - 1;

	for (int i = 0; i < 2 * tempo; i++)
		close(fds[i]);
	for (int i = 0; i < all->nbs_wait; i++) {
		wait(&(stat[i]));
		if (WIFSIGNALED(stat[i]))
			term_bled2(stat[i]);
	}
}

int make_exe(char *str, char **envi, int nbs, char **pip)
{
	all_t *all = malloc(sizeof(all_t));

	if ((pip = sepa_wordarray(str, '|')) == NULL)
		return (2);
	if ((all = init_pipes(all, nbs, pip, envi)) == NULL)
		return (2);
	if ((look_cmds(pip, all)) == 0)
		return (1);
	preli_pipe(nbs, all->ins, all->outs, all->fds);
	all->nbs_wait = nbs;
	main_pipe(nbs, all, envi, 1);
	term_bled(nbs, all->stat, all->fds, all);
	return (0);
}
