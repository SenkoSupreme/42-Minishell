#ifndef __SHELL_H
#define __SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/** ----- STRUCTS ----- **/

//WHOLE STRUCT => SEPARATE BY ; => PIPES => NORMAL WHITESPACES


/*last node the spaces one. */
typedef struct 		s_node
{
	void			*data;
	int				is_com;	//bool
	int				is_quote;
	int				is_redir;
	struct	s_node	*next;
}					t_node;

/*Pipe line struct*/
typedef	struct		s_ptoken
{
	void 			*data;
	size_t			len;
	int				is_pipe;
	struct s_ptoken	*next;
}					t_ptoken;

/*Semicol line stuct*/
typedef	struct		s_stoken 
{
	void			*data;
	size_t 			len;
	struct s_stoken	*next;	
}					t_stoken;

typedef struct		s_token
{
	char			*tok;
	char			*type;
	size_t			len;
	int				cur; 		//current pos for order
}               	t_token;

typedef struct		s_input
{
	char			*line;
	size_t			len;
	size_t			i;
}					t_input;


typedef struct 		s_array
{
	int				*array;
	int				size;
}					t_array;


typedef struct 		s_env
{
	int				ac;
	char			**av;
	char			**ev;
	t_stoken		*semitokens;
	t_ptoken		*pipetokens;
	t_node			*simpletokens;
	t_input			*input;
}					t_env;

/*---------------------------------------*/

/* -- NOVA -- */
t_input		*initiate(int ac, char **av, char **ev);
t_token		*new_token(void *tok);
t_node		*new_node(void *data);
t_ptoken	*new_pipenode(void *data);
t_stoken	*new_semicoltoken(void *data);
t_array		*new_array(int size);


/*-------------------*/

/** -- TOKENER -- **/
int 	tokenise(t_env *env);
t_node	*quotenise(t_env *env);
t_node	*single_quotenise(t_env *env);
t_node	*double_quotenise(t_env *env);
t_ptoken*split_pipe(t_env *env);
t_node	*split_node(t_env *env, char c);
t_node	*split_redirect(t_env *env);
t_token	*get_token(t_env *env, char c);
void	check_command(t_node *node);
void	check_quote(t_node **node);
void check_redirection(t_node *node);


/*-----------------*/
/* -- Reader --*/
char	*read_line(void);
int		line_is_empty(char *line);
int		shell_loop(t_env *env);
/*-------------------*/



/* uwu SENKO__FT_LIB uwu*/

/* -- PLUMER FN -- */
void	safe_free(void **ptr);


/*-- FU_Utils Functions --*/
int 	senko_getchar(void);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, int start, int end);
int		array_is_index(int index, t_array *array);
char	*senko_substr(char const *s, int start, int end, t_array *skip_index);
char 	*skip_white_spaces(char *line);
int		ft_strcmp(const char *s1,const char *s2);


/*LISTS*/
void	add_back(t_node **list, void *dt);
void	add_front(t_node **list, void *data);
void	iter_list(t_node **list, void(*fn)(void **));
size_t	list_size(t_node *list);
void	list_clear(t_node **list);
void	list_destroy(t_node **list);
void	list_delete(t_node **list);
void 	add_at_the_end(t_stoken **alst, t_stoken *l_new);
t_node	*new_new_node(void *new_data);
void 	free_node(t_node *lst, void (*del)(void*));
void	free_content(void *new_data);
void 	add_at_the_pipe(t_ptoken **alst, t_ptoken *l_new);
void 	add_at_the_node(t_node **alst, t_node *l_new);

/*----------------------*/
/* USSR Codes all rights reserved */
#endif