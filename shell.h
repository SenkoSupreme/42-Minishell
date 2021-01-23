#ifndef __SHELL_H
#define __SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define INT_ARR sizeof(int)
#define CHAR_ARR sizeof(char)
#define SHORT_ARR sizeof(short)

/** ----- STRUCTS ----- **/

// typedef struct 	source_s
// {   
// 	char *buffer;       /* the input text */
// 	long bufsize;       /* size of the input text */ 
// 	long  curpos;       /* absolute char position in source */
// }				source_t;

typedef struct 		s_node
{
	void			*data;
	struct	s_node	*next;
}					t_node;

typedef struct		s_token
{
	char			*tok;
	char			*type;
	size_t			len;
	int				cur; 		//current pos for order
	int				is_quote; 	//bool type 0 or 1;
	int				is_pipe; 

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
	t_node			*tokens;
	t_input			*input;
}					t_env;

/*---------------------------------------*/

/* -- NOVA -- */
t_input		*initiate(int ac, char **av, char **ev);
t_token	*new_token(void *tok);
t_node	*new_node(void *data);
t_array	*new_array(int size);


/*-------------------*/

/** -- TOKENER -- **/
int 	tokenise(t_env *env);
t_token	*quotenise(t_env *env);
t_token	*single_quotenise(t_env *env);
t_token	*double_quotenise(t_env *env);
t_token	*split_pipe(t_env *env);
t_token	*split_scolomn(t_env *env);
t_token	*split_redirections(t_env *env);
t_token	*get_token(t_env *env);


/*-----------------*/
/* -- Reader --*/
char	*read_line(void);
int		line_is_empty(char *line);
int	shell_loop(t_env *env);
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


/*LISTS*/
void	add_back(t_node **list, void *dt);
void	add_front(t_node **list, void *data);
void	iter_list(t_node **list, void(*fn)(void **));
size_t	list_size(t_node *list);
void	list_clear(t_node **list);
void	list_destroy(t_node **list);
void	list_delete(t_node **list);
void add_at_the_end(t_node **alst, t_node *l_new);
t_node	*new_new_node(void *new_data);
void free_node(t_node *lst, void (*del)(void*));
void			free_content(void *new_data);

/*----------------------*/

/* USSR Communists all rights reserved */
#endif