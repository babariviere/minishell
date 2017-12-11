NAME=minishell
NAME_DBG=minishelldbg
SRC_NAME=main.c shell.c parse_command.c interpret.c
SRC=$(addprefix src/, $(SRC_NAME))
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))
OBJ_DBG=$(patsubst src/%.c, obj_dbg/%.o, $(SRC))
CC=clang
LIBS=-Llibft/ -lft
LIBS_DBG=-Llibft/ -lftdbg
CFLAGS=-Wall -Werror -Wextra -Iinclude -Ilibft/include

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(NAME_DBG): $(OBJ_DBG)
	@make -C libft/ debug
	$(CC) $(CFLAGS) -g -o $(NAME_DBG) $(OBJ_DBG) $(LIBS_DBG)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

obj_dbg/%.o: src/%.c
	@mkdir -p obj_dbg
	$(CC) $(CFLAGS) -g -c -o $@ $<

debug: $(NAME_DBG)
	@lldb $(NAME_DBG)

leaks: $(NAME_DBG)
	@valgrind --leak-check=full --track-origins=yes $(NAME_DBG) 1> /dev/null

norme: $(SRC)
	@norminette $(SRC)
	@norminette include/ft_ls.h

clean:
	@make -C libft/ clean
	@rm -rf obj
	@rm -rf obj_dbg

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@rm -f $(NAME_DBG)
	@rm -rf $(NAME_DBG).dSYM

re: fclean all
