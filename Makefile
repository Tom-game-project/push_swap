CC = cc
CFLAGS = -Wextra -Werror -Wall -g

# list module sources
LIST_SRC = \
src/list/get_back.c\
src/list/init_node.c\
src/list/push.c\
src/list/util.c\
src/list/pop.c\
src/list/len.c\
src/list/get_elem.c\
src/list/set_num.c\
src/list/insert.c

# input_checker module sources
INPUT_CHECK_SRC = \
src/input_checker/input_checker.c

TEST = \
test02.c
## test04.c


# object files
LIST_OBJ = $(LIST_SRC:.c=.o)
INPUT_CHECK_OBJ = $(INPUT_CHECK_SRC:.c=.o)

# archive files
LIST_NAME = list.a
INPUT_CHECK_NAME = input_checker.a

# MAIN push swap
MAIN_SRC = push_swap.c
MAIN_TARGET = push_swap

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_SRC) $(LIST_NAME) $(INPUT_CHECK_NAME)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(LIST_NAME) $(INPUT_CHECK_NAME) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIST_NAME):$(LIST_OBJ)
	ar -rcs $@ $^

$(INPUT_CHECK_NAME):$(INPUT_CHECK_OBJ)
	ar -rcs $@ $^

test: $(TEST) $(LIST_NAME)
	rm -f test
	$(CC) $(CFLAGS) $(TEST) $(LIST_NAME) -o $@
	./test
	valgrind  --leak-check=full ./test

clean:
	rm -f $(LIST_OBJ) $(LIST_NAME) $(INPUT_CHECK_OBJ) $(INPUT_CHECK_NAME)

fclean: clean
	rm -f $(MAIN_TARGET)

re: fclean
	make all

.PHONY: all clean fclean test re
