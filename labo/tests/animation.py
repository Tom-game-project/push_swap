from labo import push_swap
from itertools import zip_longest
import sys
import subprocess
import time
from random import shuffle
import copy

# terminal
import sys
import termios
import tty


# argparse
import argparse

# magic numbers
FREE_BACKSPACE = 3

GREEN = "\033[0;32m"
END = "\033[0m"

def get_key():
    """1文字のキー入力を取得する"""
    # 現在の端末設定を保存
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        # 端末をrawモードに設定
        tty.setraw(sys.stdin.fileno())
        key = sys.stdin.read(1)  # 1文字取得
    finally:
        # 端末設定を元に戻す
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return key


def screen_stack(stack:list[int],max_value:int) -> list[str]:
    return [("=" * i).ljust(max_value," ") for i in stack]


def draw_draft(stack_a:list[int], stack_b:list[int], max_value:int) -> list[str]:
    return [row_a + '|' + row_b + '|' for row_a,row_b in zip_longest(
            screen_stack(stack_a, max_value),
            screen_stack(stack_b, max_value),
            fillvalue = max_value * ' '
        )
    ]


def run_command(psw, cmd, inverce = False):
    if inverce:
        psw.inverce_runcmd(cmd)
    else:
        psw.runcmd(cmd)


def flash_image(psw, max_value, l, cmd, inverce = False):
    dd = draw_draft(
        psw.stack_a,
        psw.stack_b,
        max_value
    )
    sys.stdout.write(f"|{GREEN}Push Swap Visualizer{END}|".center(max_value * 2 + 12, "+") +"\n")
    sys.stdout.write("h: back, l: next, q: quit" +"\n")
    sys.stdout.write("stack_a".center(max_value)+ '|'+ "stack_b".center(max_value) +"\n")
    for row in dd:
        sys.stdout.write(row+"\n")
    if len(dd) < l:
        for i in range(l - FREE_BACKSPACE - len(dd)):
            sys.stdout.write(" " * (max_value * 2 + 2) +"\n")
    sys.stdout.write("\033[F" * l)
    sys.stdout.flush()


def animation(lst:list[int], operations:list[str]):
    play_flag = False
    i = 0
    max_value = max(lst)
    l = len(lst) + FREE_BACKSPACE
    psw = push_swap(lst)
    cmd = operations[i]
    flash_image(psw, max_value, l, cmd)
    while True:
        key = get_key()
        if key == 'h':
            if 0 < i < len(operations):
                i -= 1
                cmd = operations[i]
                run_command(psw, cmd, inverce = True)
                flash_image(psw, max_value, l, cmd, inverce=True)
        elif key == 'l':
            if 0 <= i < len(operations) - 1:
                cmd = operations[i]
                run_command(psw, cmd)
                flash_image(psw, max_value, l, cmd)
                i += 1
        elif key == 'q':
            return "q"
        elif key == 'r':
            return "r"
        elif key == 'o':
            return "o"



if __name__ == "__main__":
    # ArgumentParserを作成
    parser = argparse.ArgumentParser(description="Push Swap Visualizer")

    parser.add_argument("path_to_push_swap", help="Path to executable push_swap file")
    parser.add_argument("-l", "--length", type=int, help="Stack length at initialization", default=20)

    args = parser.parse_args()


    a = list(range(args.length))
    shuffle(a)
    lst_tmp = copy.deepcopy(a)
    while True:
        out = subprocess.run([
                args.path_to_push_swap,
                *list(map(str, a))
            ],
            encoding="utf-8",
            stdout=subprocess.PIPE
        )
        r = animation(a, out.stdout.split("\n"))
        if r == 'q':
            break
        elif r == 'r':
            a = copy.deepcopy(lst_tmp)
            continue
        elif r == 'o':
            a = list(range(args.length))
            shuffle(a)
            lst_tmp = copy.deepcopy(a)
            continue

