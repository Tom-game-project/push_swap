CC = cc
CFLAGS = -Wextra -Werror -Wall -fsanitize=address

# list module sources
LIST_SRC = \
src/list/get_back.c\
src/list/init_node.c\
src/list/list.c\
src/list/push.c\
src/list/util.c


LIST_OBJ = $(LIST_SRC:.c=.o)

LIST_NAME = list.a

# MAIN push swap
MAIN_SRC = push_swap.c
MAIN_TARGET = push_swap

all: $(MAIN_TARGET)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_TARGET): $(MAIN_SRC) $(LIST_OBJ)
	$(CC) $(CFLAGS) -o $(MAIN_SRC) $(LIST_OBJ)

$(LIST_NAME):$(LIST_OBJ)
	ar -rcs $@ $^

clean:
	rm -f $(LIST_OBJ) $(LIST_NAME)

fclean: clean
	rm -f $(MAIN_TARGET)

.PHONY: all clean fclean