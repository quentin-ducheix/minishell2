/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int redir(all_t *all, int i)
{
	int tempo = 0644;
	int fd = 0;
	int flags = O_CREAT | O_RDWR;

	if (all->com[i]->check_redir == 1)
		flags = flags | O_TRUNC;
	else if (all->com[i]->check_redir != 1)
		flags = flags | O_APPEND;
	fd = open(all->com[i]->redir, flags, tempo);
	if (fd == -1 || (dup2(fd, 1)) == -1)
		return (84);
	return (fd);
}

int eazy_redil(all_t *all, int i)
{
	int fd = open(all->com[i]->redil, O_RDONLY);

	if (fd == -1) {
		bled(1);
		my_putstr(all->com[i]->redil);
		my_putstr(": no such file\n");
		return (84);
	}
	if ((dup2(fd, 0)) == -1)
		return (84);
	return (fd);
}

int double_redil(all_t *all, int i, char *buf)
{
	all->fds = malloc(sizeof(int) * 2);
	if (all->ins[i] != -1)
		close(all->ins[i]);
	if ((pipe(all->fds)) == -1)
		return (84);
	write(all->fds[1], buf, my_strlen(buf));
	close(all->fds[1]);
	if ((dup2(all->fds[0], 0)) == -1)
		return (84);
	return (all->fds[0]);
}

int redil(all_t *all, int i)
{
	char *buf = NULL;
	char *tempo = NULL;
	size_t k = 0;
	int rtn = 0;

	if (all->com[i]->check_redil == 1) {
		rtn = eazy_redil(all, i);
		return (rtn);
	}
	for (int j = 0; redir_string(buf, all->com[i]->redil) != 1; j++) {
		my_putstr("> ");
		tempo[(getline(&tempo, &k, stdin)) - 1] = '\0';
		buf = the_realloc(buf, tempo);
		if (buf == NULL)
			return (84);
	}
	buf = clening_string(buf);
	rtn = double_redil(all, i, buf);
	return (rtn);
}

int do_redir_it(all_t *all, int i, int is_it)
{
	int tempo = 0;

	if (all->com[i]->check_redil != 0)
		tempo = redil(all, i);
	else if (is_it == 1 && all->ins[i] != -1 &&
	(dup2(all->ins[i], 0)) == -1)
		return (2);
	if (all->com[i]->check_redir != 0)
		tempo = tempo + redir(all, i);
	else if (is_it == 1 && all->outs[i] != -1 &&
	(dup2(all->outs[i], 1)) == -1)
		return (2);
	return (tempo);
}
