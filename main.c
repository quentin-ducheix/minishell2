/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int all_spaces(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] != ' ')
			return (0);
	}
	return (2);
}

void signal_handle(int sig_num)
{
	(void)sig_num;
}

int second(char **str_com, int *tmp, int *tempo_exe, int *verif)
{
	if ((*str_com) == NULL || (*str_com)[0] == '\0')
		exit(bled(-99));
	if (isatty(0) == 0 && (*str_com)[0] == '\0')
		exit(bled(-99));
	bled(0);
	(*str_com)[(*tmp) - 1] = '\0';
	(*str_com)[(*tmp)] = '\0';
	if (my_strlen(*str_com) == 0) {
		(*tempo_exe) = 0;
		(*verif) = 1;
	}
	if (checkit(*str_com) == 2 || all_spaces(*str_com) == 2) {
		(*tempo_exe) = 0;
		(*verif) = 1;
	}
	return (0);
}

int third(char ***str_arr, int *verif, int *tempo, int *tempo_exe, char ***env)
{
	for (int i = 0; (*str_arr)[i] && *verif == 0 &&
	(*str_arr)[i][0] != '\0'; i++) {
		*tempo = make_exe((*str_arr)[i], *env,
		find_nbs_compip((*str_arr)[i]), NULL);
		if (*tempo == 1) {
			*tempo_exe = 0;
			break;
		} else if (*tempo != 0) {
			*tempo_exe = *tempo;
			break;
		} else if (*tempo == 0)
			*tempo_exe = 0;
	}
	if (*tempo_exe != 0)
		exit ((*tempo_exe == -3) ? (0) : (*tempo_exe));
	return (0);
}

int main(int argc, char **argv, char **env)
{
	int tempo_exe = 0;
	char *str_com = NULL;
	char **str_arr = NULL;
	int tempo = 0;
	int tmp = 0;
	size_t j = 0;
	int verif = 0;
	(void)argc;
	(void)argv;

	while (1) {
		str_com = NULL;
		str_arr = NULL;
		tempo = 0;
		tmp = 0;
		j = 0;
		if (isatty(0) == 1)
			my_putstr("$> ");
		tmp = getline(&str_com, &j, stdin);
		second(&str_com, &tmp, &tempo_exe, &verif);
		if ((str_arr = sepa_wordarray(str_com, ';')) == NULL) {
			tempo_exe = -1;
			verif = 1;
		}
		third(&str_arr, &verif, &tempo, &tempo_exe, &env);
		verif = 0;
		signal(SIGINT, signal_handle);
	}
	return (0);
}
