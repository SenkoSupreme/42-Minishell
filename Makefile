
NAME=minishell

SRC = srcs/*.c minishell.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME):
	@make CC=$(CC) -C libft bonus 
	@$(CC) $(FLAGS) $(SRC) libft/libft.a -Iincludes -o $(NAME)

clean :
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: fclean clean all re