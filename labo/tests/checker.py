from labo import push_swap
# import argparse
import sys
import subprocess


if __name__ == "__main__":
    a = [5,2,7,3,1,6,4]
    out = subprocess.run(["./../test"],encoding="utf-8",stdout=subprocess.PIPE)
    print(out.stdout.split('\n'))
    # print(list(map(int, sys.argv[1:])))
    psw = push_swap(a)
    for cmd in out.stdout.split('\n'):
        print("stack_a", psw.stack_a)
        print("stack_b", psw.stack_b)
        psw.runcmd(cmd)

    print("stack_a", psw.stack_a)
    print("stack_b", psw.stack_b)
