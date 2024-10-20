from labo import push_swap
from itertools import zip_longest
import sys
import subprocess
import time
from random import shuffle

# def animation3(operations:list[str]):
#     # print(out.stdout.split('\n'))
#     psw = push_swap(a)
#     for cmd in operations:
#         sys.stdout.write("stack_a" + f"{psw.stack_a}".rjust(50)+ "\n")
#         sys.stdout.write("stack_b" + f"{psw.stack_b}".rjust(50))
#         sys.stdout.flush()
#         psw.runcmd(cmd)
#         sys.stdout.write("\033[F")
#         time.sleep(0.1)
#     sys.stdout.write("stack_a" + f"{psw.stack_a}".rjust(50)+ "\n")
#     sys.stdout.write("stack_b" + f"{psw.stack_b}".rjust(50)+ "\n")


def screen_stack(stack:list[int],max_value:int) -> list[str]:
    return [("=" * i).ljust(max_value," ") for i in stack]

def draw_draft(stack_a:list[int], stack_b:list[int], max_value:int) -> list[str]:
    return [row_a + '|' + row_b + '|' for row_a,row_b in zip_longest(
            screen_stack(stack_a, max_value),
            screen_stack(stack_b, max_value),
            fillvalue = max_value * ' '
        )
    ]

def animation4(lst:list[int], operations:list[str]):
    max_value = max(lst)
    l = len(lst) + 1
    psw = push_swap(lst)
    for cmd in operations:
        dd = draw_draft(
            psw.stack_a,
            psw.stack_b,
            max_value
        )
        sys.stdout.write("stack_a".center(max_value)+ '|'+ "stack_b".center(max_value) +"\n")
        for row in dd:
            sys.stdout.write(row+"\n")
        if len(dd) < l:
            for i in range(l - 1 - len(dd)):
                sys.stdout.write(" " * (max_value * 2 + 2) +"\n")
        sys.stdout.flush()
        psw.runcmd(cmd)
        sys.stdout.write("\033[F" * l)
        time.sleep(0.01)


if __name__ == "__main__":
    a = list(range(100))
    shuffle(a)
    out = subprocess.run([
            "./../push_swap",
            *list(map(str, a))
        ],
        encoding="utf-8",
        stdout=subprocess.PIPE
    )
    # animation3(out.stdout.split("\n"))
    animation4(a, out.stdout.split("\n"))