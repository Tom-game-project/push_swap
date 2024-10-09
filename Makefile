CC = cc
CFLAGS = -Wextra -Werror -Wall -g

# `list` module sources
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

# `input_checker` module sources
INPUT_CHECK_SRC = \
src/input_checker/input_checker.c

# `output` module sources
OUTPUT_SRC = \
src/output/output.c

STRNUMTOOLS_SRC = \
src/strnumtools/comp.c

TEST = \
testlt.c
# test02.c
## test04.c

# object files
LIST_OBJ = $(LIST_SRC:.c=.o)
INPUT_CHECK_OBJ = $(INPUT_CHECK_SRC:.c=.o)
OUTPUT_OBJ = $(OUTPUT_SRC:.c=.o)
STRNUMTOOLS_OBJ = $(STRNUMTOOLS_SRC:.c=.o)

# object files
OBJS = \
$(LIST_OBJ)\
$(INPUT_CHECK_OBJ)\
$(OUTPUT_OBJ)\
$(STRNUMTOOLS_OBJ)

# archive files
LIST_NAME = list.a
INPUT_CHECK_NAME = input_checker.a
OUTPUT_NAME = output.a
STRNUMTOOLS_NAME = strnumtools.a

# archives files
ARCHIVES = \
$(LIST_NAME)\
$(INPUT_CHECK_NAME)\
$(OUTPUT_NAME)\
$(STRNUMTOOLS_NAME)

# MAIN push swap
MAIN_SRC = src/push_swap.c
MAIN_TARGET = push_swap

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_SRC) $(ARCHIVES)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(ARCHIVES) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

# archive make rules
$(LIST_NAME):$(LIST_OBJ)
	ar -rcs $@ $^

$(INPUT_CHECK_NAME):$(INPUT_CHECK_OBJ)
	ar -rcs $@ $^

$(OUTPUT_NAME):$(OUTPUT_OBJ)
	ar -rcs $@ $^

$(STRNUMTOOLS_NAME):$(STRNUMTOOLS_OBJ)
	ar -rcs $@ $^

# test make rules
test: $(TEST) $(ARCHIVES)
	rm -f test
	$(CC) $(CFLAGS) $(TEST) $(ARCHIVES) -o $@
	./test
	valgrind  --leak-check=full ./test

clean:
	rm -f $(OBJS) $(ARCHIVES)

fclean: clean
	rm -f $(MAIN_TARGET)

re: fclean
	make all

.PHONY: all clean fclean test re
