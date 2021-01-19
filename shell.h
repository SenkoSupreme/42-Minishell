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

typedef struct 	source_s
{   
	char *buffer;       /* the input text */
	long bufsize;       /* size of the input text */ 
	long  curpos;       /* absolute char position in source */
}				source_t;


typedef struct		s_token
{
	char			*tok;
	char			*type;
	size_t			len;
	int				cur; 		//current pos for order
	int				is_quote; 	//bool type 0 or 1;

}               	t_token;

typedef struct		s_input
{
	char			*line;
	size_t			len;
	size_t			i;
}					t_input;

typedef struct 		s_node
{
	void			*data;
	struct	s_node	*next;
}					t_node;

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
t_env		*initiate(int ac, char **av, char **ev);
t_token		*new_token(void *tok);


/*-------------------*/

/** -- TOKENER -- **/
int tokenise(t_env *env);
t_token	*quotenise(t_env *env);
t_token	*sigle_quotenise(t_env *env);
t_token	*double_quotenise(t_env *env);


/*-----------------*/
/* -- Reader --*/
char	*read_line(void);
/*-------------------*/



/* uwu SENKO__FT_LIB uwu*/


/*-- FU_Utils Functions --*/
int 	senko_getchar(void);
void	ft_putstr(char const *s);
int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
/*LISTS*/
void	add_back(t_node **list, void *data);
/*----------------------*/

/* USSR Communists all rights reserved */
#endif