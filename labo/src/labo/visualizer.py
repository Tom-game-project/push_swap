from labo import push_swap
import curses
from itertools import zip_longest

def loop(stdscr:"curses._CursesWindow"):
    key = -1
    curses.curs_set(0)
    stdscr.nodelay(1)
    stdscr.timeout(200)
    while True:
        stdscr.clear()

        key = stdscr.getch()



def screen_stack(stack:list[int],max_value:int) -> list[str]:
    return [("-" * i).ljust(max_value," ") for i in stack]

def draw_draft(stack_a:list[int], stack_b:list[int], max_value:int) -> list[str]:
    return [row_a + row_b for row_a,row_b in zip_longest(
        #    :int  :int
        screen_stack(stack_a,max_value),
        screen_stack(stack_b,max_value),
        fillvalue = max_value * ' '
        )
    ]