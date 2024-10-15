from labo import push_swap
# import argparse
import sys
import subprocess
import time
import sys

if __name__ == "__main__":
    a = [5,2,7,3,1,6,4]
    out = subprocess.run(["./../test"],encoding="utf-8",stdout=subprocess.PIPE)
    print("length od stdin",len(out.stdout.split('\n')))
    psw = push_swap(a)
    for cmd in out.stdout.split('\n'):
        print("stack_a", psw.stack_a)
        print("stack_b", psw.stack_b)
        psw.runcmd(cmd)

    print("stack_a", psw.stack_a)
    print("stack_b", psw.stack_b)
    print("step", psw.step)
    # animation3()