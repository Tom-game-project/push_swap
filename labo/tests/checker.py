from labo import push_swap
# import argparse
import subprocess
from random import shuffle
import sys
import itertools


# 簡易的なチェッカー
# True -> is sorted 
# False -> is not sorted
def checker(a:list,operations: list[str]):
    psw = push_swap(a)
    for cmd in operations:
        # print("stack_a", psw.stack_a)
        # print("stack_b", psw.stack_b)
        psw.runcmd(cmd)

    # print("stack_a", psw.stack_a)
    # print("stack_b", psw.stack_b)
    print("step", psw.step)
    return all(i < j for i, j in zip(psw.stack_a[: -1], psw.stack_a[1:]))

def check(a:list):
    print(a,end="")
    out = subprocess.run([
            "./../push_swap",
            *list(map(str, a))
        ],
        encoding="utf-8",
        stdout=subprocess.PIPE
    )
    out = out.stdout.split("\n")
    return checker(a, out)


if __name__ == "__main__":
    print("len 3")
    if all(check(list(a)) for i,a in enumerate(itertools.permutations(range(3)))):
        print("ok")
    else:
        print("kick!")
    print("len 4")
    if all(check(list(a)) for i,a in enumerate(itertools.permutations(range(4)))):
        print("ok")
    else:
        print("kick!")
    print("len 5")
    if all(check(list(a)) for i,a in enumerate(itertools.permutations(range(5)))):
        print("ok")
    else:
        print("kick!")

