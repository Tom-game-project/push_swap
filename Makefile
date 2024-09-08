CC = cc
CFLAGS = -Wextra -Werror -Wall -g

# list module sources
LIST_SRC = \
src/list/get_back.c\
src/list/init_node.c\
src/list/list.c\
src/list/push.c\
src/list/util.c\
src/list/pop.c\
src/list/len.c\
src/list/get_elem.c\
src/list/assignment.c\
src/list/insert.c

TEST = \
test00.c


LIST_OBJ = $(LIST_SRC:.c=.o)

LIST_NAME = list.a

# MAIN push swap
MAIN_SRC = push_swap.c
MAIN_TARGET = push_swap

all: $(MAIN_TARGET)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_TARGET): $(MAIN_SRC) $(LIST_OBJ)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LIST_OBJ) -o $@


$(LIST_NAME):$(LIST_OBJ)
	ar -rcs $@ $^

test: $(TEST) $(LIST_OBJ)
	$(CC) $(CFLAGS) $(TEST) $(LIST_OBJ) -o $@

clean:
	rm -f $(LIST_OBJ) $(LIST_NAME)

fclean: clean
	rm -f $(MAIN_TARGET)

re: fclean
	make all

.PHONY: all clean fclean test