NAME_P := push_swap
NAME_C := ./checker/checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = algo_bigger.c algo_short.c case.c check.c get.c \
	init.c list_sort.c list_u1.c list_u2.c list.c \
	main.c norm.c op_call.c op_call2.c op_p.c op_r.c \
	op_s.c utiles.c utiles2.c utiles3.c

SRCB = ./checker/init_stacks.c ./checker/checker.c \
	./checker/instructions.c ./checker/operations.c \
	./checker/utiles2.c ./checker/utiles.c

OBJECTS = $(SRC:.c=.o)

OBJECTSB = $(SRCB:.c=.o)

all: $(NAME_P)

$(NAME_P): $(OBJECTS)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) -o $(NAME_P) $(OBJECTS)
	@echo "\n\033[0;32mDone."

$(NAME_C): $(OBJECTSB)
	@$(CC) -o $(NAME_C) $(OBJECTSB)

bonus: $(NAME_C) $(NAME_P)

%.o:%.c push_swap.h ./checker/checker.h
	@printf "\033[0;33mGenerating pipex objects... %-10.10s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJECTS) $(OBJECTSB)
	@echo "\n\033[0;31mDeleted.\n"	

fclean: clean
	@rm -f $(NAME_P) $(NAME_C)

re: fclean all

norm:
	norminette . ./checker