CC = cc
CFLAGS = -Wextra -Werror -Wall -g

# `list` module sources
LIST_SRC = \
src/list/clear.c\
src/list/init_node.c\
src/list/push.c\
src/list/util.c\
src/list/pop.c\
src/list/len.c\
src/list/get_elem.c\
src/list/set_num.c\
src/list/insert.c\
src/list/merge_sort.c\
src/list/is_sorted.c


# `input_checker` module sources
INPUT_CHECK_SRC = \
src/input_checker/input_checker.c

SWAP_SRC = \
src/swap/swap0.c\
src/swap/swap1.c\
src/swap/swap2.c\
src/swap/swap3.c\
src/swap/oswap.c

# `output` module sources
OUTPUT_SRC = \
src/output/output.c

STRNUMTOOLS_SRC = \
src/strnumtools/comp.c

TEST = \
tests/testlt.c
# tests/mtest00.c
# tests/test02.c
# tests/test00.c
# tests/test01.c
# tests/test03.c
# tests/test04.c

# object files
SWAP_OBJ = $(SWAP_SRC:.c=.o)
LIST_OBJ = $(LIST_SRC:.c=.o)
INPUT_CHECK_OBJ = $(INPUT_CHECK_SRC:.c=.o)
OUTPUT_OBJ = $(OUTPUT_SRC:.c=.o)
STRNUMTOOLS_OBJ = $(STRNUMTOOLS_SRC:.c=.o)

# object files
OBJS = \
$(SWAP_OBJ)\
$(LIST_OBJ)\
$(INPUT_CHECK_OBJ)\
$(OUTPUT_OBJ)\
$(STRNUMTOOLS_OBJ)

# archive files
SWAP_NAME = swap.a
LIST_NAME = list.a
INPUT_CHECK_NAME = input_checker.a
OUTPUT_NAME = output.a
STRNUMTOOLS_NAME = strnumtools.a

# archives files
ARCHIVES = \
$(SWAP_NAME)\
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

$(SWAP_NAME): $(SWAP_OBJ)
	ar -rcs $@ $^

$(LIST_NAME):$(SWAP_OBJ) $(LIST_OBJ) 
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
	# ./test
	valgrind  --leak-check=full ./test

clean:
	rm -f $(OBJS) $(ARCHIVES)

fclean: clean
	rm -f $(MAIN_TARGET)

re: fclean
	make all

.PHONY: all clean fclean test re
