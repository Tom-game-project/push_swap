from labo import push_swap
from itertools import zip_longest
import sys
import subprocess
import time
from random import shuffle

# terminal
import sys
import termios
import tty


# argparse
import argparse


FREE_BACKSPACE = 3

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
    sys.stdout.write("\033[0;32mPush Swap Visualizer\033[0m".center(50, "*") +"\n")
    sys.stdout.write("h: back, l: next, q: quit" +"\n")
    sys.stdout.write("stack_a".center(max_value)+ '|'+ "stack_b".center(max_value) +"\n")
    for row in dd:
        sys.stdout.write(row+"\n")
    if len(dd) < l:
        for i in range(l - FREE_BACKSPACE - len(dd)):
            sys.stdout.write(" " * (max_value * 2 + 2) +"\n")
    sys.stdout.write("\033[F" * l)
    sys.stdout.flush()


def animation4(lst:list[int], operations:list[str]):
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
            break


if __name__ == "__main__":
    # ArgumentParserを作成
    parser = argparse.ArgumentParser(description="サンプルスクリプト")

    # 引数を追加
    parser.add_argument("path_to_push_swap", help="Path to executable push_swap file")
    parser.add_argument("-l", "--length", type=int, help="Stack length at initialization", default=20)

    # 引数を解析
    args = parser.parse_args()

    a = list(range(args.length))
    shuffle(a)
    out = subprocess.run([
            args.path_to_push_swap, # "./../push_swap"
            *list(map(str, a))
        ],
        encoding="utf-8",
        stdout=subprocess.PIPE
    )
    # animation3(out.stdout.split("\n"))
    animation4(a, out.stdout.split("\n"))
