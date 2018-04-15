/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

void play_env2(all_t *all1, char **envi, all_t *all)
{
	int fd = do_redir_it(all1, 0, 0);

	for (int i = 0; envi[i]; i++) {
		if (all->check_redir != 0) {
			my_putstr(envi[i]);
			my_putstr("\n");
		} else {
			my_putstr(envi[i]);
			my_putstr("\n");
		}
	}
	close(fd);
	exit(0);
}

int play_env(char **envi, all_t *all)
{
	int pid;
	int stat = 0;
	all_t *all1 = malloc(sizeof(all_t));

	all1->com = malloc(sizeof(all_t *) * 2);
	all1->com[0] = all;
	all1->com[1] = NULL;
	pid = fork();
	if (pid == 0)
		play_env2(all1, envi, all);
	else if (pid > 0)
		wait(&stat);
	else if (pid == -1)
		return (0);
	return (0);
}
