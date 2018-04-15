/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

typedef struct all_s {
	char *fname;
	char *path;
	char **avs;
	int check_redir;
	char *redir;
	int check_redil;
	char *redil;
	int *stat;
	int *ins;
	int *outs;
	int *fds;
	int nbs_wait;
	struct all_s **com;
	int i;
	int zeros;
	int u;
} all_t;

//lib
char **my_str_to_word_array(char *);
void my_putchar(char);
int my_strlen(char const *);
int my_putstr(char *);
char *my_strdup(char *);
char *my_strcat(char *, char const *);
int my_strncmp(char const *, char const *, int);
char *get_term(char **);
int my_strcmp(char const *, char const *);
int my_get_nbr (char *);
char *my_strchr(char *, int);
int solo_spaces(char *);
int line_enter(char *);
int redir_string(char *, char *);
char *clening_string(char *);

//SRC
int bultis(char *);
int built_it(all_t *, all_t *, char **);
int for_exit(char *);
int bled(int);
int checker_redi(char *);
int checkit(char *);
int main_pipe(int, all_t *, char **, int);
void term_bled(int, int *, int *, all_t *);
int make_exe(char *, char **, int, char **);
char **path_to_wordtab(char *);
char *free_paths(char **, int);
char *is_path_good(char *);
char *search(char *, char **, int);
char *search_com(char *, char **, int);
char *get_redi_file(char *);
int catch_rredi(char *, all_t *);
int catch_lredi(char *, all_t *);
void rm_redi_file(char *);
char *str_noredi(char *, all_t *);
char *past_path(char **, all_t *);
char *full_path(char **, char *);
int sauv(char *, char **, all_t *);
int my_cd(all_t *, char **);
void play_env2(all_t *, char **, all_t *);
int play_env(char **, all_t *);
int comnull(all_t *, char *);
int com_maker(all_t *, char **, all_t *, int);
int do_with_env(all_t *, char **, int, int);
int before_setenv(char ***, char *, all_t *);
char *look_env(char **, char *);
int is_env(char *);
int look_env_opt(all_t *, all_t *);
char **save_envi(char **);
int do_it_env(char **, all_t *, all_t *, int);
int the_env(char **, all_t *);
int moenv(char **, char *);
void cpyenv(char **, char ***);
int commit_env(char ***, char *, char *);
char *plus_egal(char *);
int the_setenv(char ***, char *, char *, all_t *);
int the_unsetenv(char ***, all_t *);
int find_nbs_compip(char *);
int preli_pipe(int, int *, int *, int *);
all_t *init_pipes(all_t *, int, char **, char **);
int look_cmds(char **, all_t *);
char *the_realloc(char *, char *);
int redir(all_t *, int);
int eazy_redil(all_t *, int);
int double_redil(all_t *, int, char *);
int redil(all_t *, int);
int do_redir_it(all_t *, int, int);
int nbs_sepa(char *, char);
char *duplistr(char *, char *, char);
char *get_it_str(char *, int, char);
char **sepa_wordarray(char *, char);
char *catch_redi(char *, all_t *);
all_t *trans_str_cmd(char *, char **);

#endif
