/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int catch_rredi(char *str, all_t *all)
{
	int i = 0;
	int w = 0;
	char *tempo = NULL;
	int j = 0;

	if (str[0] == '>' && i++)
		all->check_redir = 2;
	for (;str[i] == ' '; i++);
	tempo = str + i;
	for (; tempo && tempo[w] && tempo[w] != ' '; w++);
	all->redir = malloc(sizeof(char) * (w + 1));
	for (; tempo && tempo[j] && tempo[j] != ' '; j++)
		all->redir[j] = tempo[j];
	all->redir[j] = '\0';
	return (0);
}

int catch_lredi(char *str, all_t *all)
{
	int i = 0;
	int w = 0;
	char *tempo = NULL;
	int j = 0;

	if (str[0] == '<' && i++)
		all->check_redil = 2;
	for (; str[i] == ' '; i++);
	tempo = str + i;
	for (; tempo && tempo[w] && tempo[w] != ' '; w++);
	all->redil = malloc(sizeof(char) * (w + 1));
	for (; tempo && tempo[j] && tempo[j] != ' '; j++)
		all->redil[j] = tempo[j];
	all->redil[j] = '\0';
	return (0);
}

char *str_noredi(char *str, all_t *all)
{
	int j = 0;
	char *tempo = NULL;

	if (all->check_redir == 0 && all->check_redil == 0)
		return (str);
	for (int i = 0; str[i]; i++) {
		if (str[i] == '>' || str[i] == '<') {
			j = 0;
			tempo = str + i;
			(tempo)[0] = ' ';
			if ((tempo)[1] == '>' || (tempo)[1] == '<')
			(tempo)[1] = ' ';
			for (; (tempo)[j] == ' '; j++);
			for (; (tempo)[j] && (tempo)[j] != ' '; j++)
			(tempo)[j] = ' ';
		}
	}
	return (str);
}
