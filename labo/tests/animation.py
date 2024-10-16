from labo import push_swap
# from labo import visualizer
from itertools import zip_longest
from pprint import pprint
# import argparse
import sys
import subprocess
import time
import sys

def animation3():
    a = [5,2,7,3,1,6,4]
    out = subprocess.run(["./../test"],encoding="utf-8",stdout=subprocess.PIPE)
    # print(out.stdout.split('\n'))
    psw = push_swap(a)
    for cmd in out.stdout.split('\n'):
        sys.stdout.write("stack_a" + f"{psw.stack_a}".rjust(50)+ "\n")
        sys.stdout.write("stack_b" + f"{psw.stack_b}".rjust(50))
        sys.stdout.flush()
        psw.runcmd(cmd)
        sys.stdout.write("\033[F")
        time.sleep(0.1)
    sys.stdout.write("stack_a" + f"{psw.stack_a}".rjust(50)+ "\n")
    sys.stdout.write("stack_b" + f"{psw.stack_b}".rjust(50)+ "\n")


def screen_stack(stack:list[int],max_value:int) -> list[str]:
    return [("-" * i).ljust(max_value," ") for i in stack]

def draw_draft(stack_a:list[int], stack_b:list[int], max_value:int) -> list[str]:
    return [row_a + '|' + row_b + '|' for row_a,row_b in zip_longest(
            screen_stack(stack_a, max_value),
            screen_stack(stack_b, max_value),
            fillvalue = max_value * ' '
        )
    ]

def animation4():
    a = [5,2,7,3,1,6,4]
    out = subprocess.run(["./../test"],encoding="utf-8",stdout=subprocess.PIPE)
    max_value = max(a)
    l = len(a) + 1
    psw = push_swap(a)
    for cmd in out.stdout.split('\n'):
        dd = draw_draft(
            psw.stack_a,
            psw.stack_b,
            max_value
        )
        # sys.stdout.write(" " * (max_value * 2 + 2) +"\n")
        sys.stdout.write("stack_a".center(max_value)+ '|'+ "stack_b".center(max_value) +"\n")
        for row in dd:
            sys.stdout.write(row+"\n")
        if len(dd) < l:
            for i in range(l - 1 - len(dd)):
                sys.stdout.write(" " * (max_value * 2 + 2) +"\n")
        sys.stdout.flush()
        psw.runcmd(cmd)
        sys.stdout.write("\033[F" * l)
        time.sleep(0.2)


if __name__ == "__main__":
    animation4()