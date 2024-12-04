from labo import push_swap
# import argparse
import subprocess
from random import shuffle
import sys


# 簡易的なチェッカー
def checker(operations: list[str]):
    psw = push_swap(a)
    for cmd in operations:
        # print("stack_a", psw.stack_a)
        # print("stack_b", psw.stack_b)
        psw.runcmd(cmd)

    # print("stack_a", psw.stack_a)
    # print("stack_b", psw.stack_b)
    print("step", psw.step)
    if all(i < j for i, j in zip(psw.stack_a[: -1], psw.stack_a[1:])):
        print("is sorted")
    else:
        print("is not sorted")


if __name__ == "__main__":
    a = list(range(int(sys.argv[1])))
    shuffle(a)
    out = subprocess.run([
            "./../push_swap",
            *list(map(str, a))
        ],
        encoding="utf-8",
        stdout=subprocess.PIPE
    )
    checker(out.stdout.split("\n"))
