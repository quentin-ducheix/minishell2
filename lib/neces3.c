/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (*str) {
		str++;
		i++;
	}
	return (i);
}

int my_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		my_putchar (str[i]);
		i++;
	}
	return (0);
}

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int o = 0;
	char *new = NULL;

	i = my_strlen(dest);
	k = my_strlen(src);
	new = malloc(sizeof(char) * (i + k + 2));
	while (dest[j] != '\0') {
		new[j] = dest[j];
		j++;
	}
	while(src[o] != '\0') {
		new[j + o] = src[o];
		o++;
	}
	new[j + o] = '\0';
	return (new);
}

void cpyenv(char **env, char ***nenvi)
{
	int i = 0;

	for (; env[i]; i++);
	*nenvi = malloc(sizeof(char*) * i + 2);
	*nenvi = env;
}
