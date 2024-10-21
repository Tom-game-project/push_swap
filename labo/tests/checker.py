from labo import push_swap
# import argparse
import sys
import subprocess
import time
import sys
from random import shuffle

# 簡易的なチェッカー
def checker(operations:list[str]):
    psw = push_swap(a)
    for cmd in operations:
        # print("stack_a", psw.stack_a)
        # print("stack_b", psw.stack_b)
        psw.runcmd(cmd)

    print("stack_a", psw.stack_a)
    print("stack_b", psw.stack_b)
    print("step", psw.step)

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
    checker(out.stdout.split("\n"))
