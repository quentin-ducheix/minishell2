/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

char *catch_redi(char *str, all_t *com)
{
	com->check_redir = 0;
	com->check_redil = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '>') {
			com->check_redir = 1;
			catch_rredi(str + i + 1, com);
			if (str[i + 1] == '>')
				i++;
		} else if (str[i] == '<') {
			com->check_redil = 1;
			catch_lredi(str + i + 1, com);
			if (str[i + 1] == '<')
				i++;
		}
	}
	str = str_noredi(str, com);
	return (str);
}

all_t *trans_str_cmd(char *str, char **envi)
{
	all_t *com = malloc(sizeof(all_t));
	int i = 0;
	int w = 0;

	str = catch_redi(str, com);
	for (; str[i] && str[i] == ' '; i++);
	com->fname = malloc(sizeof(char) * (my_strlen(str) + 1));
	com->path = NULL;
	com->avs = NULL;
	for (; str[i + w] && str[i + w] != ' '; w++)
		com->fname[w] = str[i + w];
	com->fname[w] = '\0';
	com->avs = my_str_to_word_array(str + i);
	if (com->avs == NULL)
		return (NULL);
	com->path = search_com(com->avs[0], envi, 0);
	return (com);
}
