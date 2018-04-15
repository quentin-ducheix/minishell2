/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while((s1[i] != '\0')  && (s1[i] == s2[i]) && i < n-1) {
		i = i + 1;
	}
	if ((*s1 == '\0' && *s2 == '\0')||(n ==0))
		return (0);
	if (n == 1 || *s1 == '\0' || *s2 == '\0' || i == 0)
		return (s1[i] - s2[i]);
	else
		return (s1[i] - s2[i]);
}

char *get_term(char **env)
{
	if (env == NULL || *env == NULL)
		return (NULL);
	for (int i = 0; env[i]; i++)
		if (my_strncmp("TERM=", env[i], 5) == 0)
			return (&(env[i][5]));
	return (NULL);
}

int my_strcmp(char const *s1, char const *s2)
{
	int diff_sub;
	int i = 0;

	while((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i])) {
		i++;
	}
	diff_sub = s1[i] - s2[i];
	return (diff_sub);
}

int my_get_nbr (char *str)
{
	int nb = 0;
	int verif = 1;
	int i = 0;

	if (str[i] == '-') {
		verif = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	return (nb * verif);
}

char *my_strchr(char *s, int c)
{
	for (int i = 0; s[i]; i++)
		if (s[i] == c)
			return (s + i);
	return (NULL);
}
