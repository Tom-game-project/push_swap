from labo import push_swap
import itertools
import subprocess


def checking_input_pattern():
    for i, j in enumerate(itertools.permutations(range(5))):
        print(i, j)
        testing(j)


# 簡易的なチェッカー
def checker(a: list[int], operations: list[str]):
    psw = push_swap(a)
    for cmd in operations:
        # print("stack_a", psw.stack_a)
        # print("stack_b", psw.stack_b)
        psw.runcmd(cmd)

    # print("stack_a", psw.stack_a)
    # print("stack_b", psw.stack_b)
    print("step", psw.step)


def testing(a: list[int]):
    lst = list(map(str, a))
    print(lst)
    out = subprocess.run([
            "./../push_swap",
            *lst
        ],
        encoding="utf-8",
        stdout=subprocess.PIPE
    )
    checker(lst, out.stdout.split("\n"))


if __name__ == "__main__":
    checking_input_pattern()
