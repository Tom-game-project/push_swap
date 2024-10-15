from labo import push_swap
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

if __name__ == "__main__":
    # a = [5,2,7,3,1,6,4]
    # out = subprocess.run(["./../test"],encoding="utf-8",stdout=subprocess.PIPE)
    # print(out.stdout.split('\n'))
    # psw = push_swap(a)
    # for cmd in out.stdout.split('\n'):
    #     print("stack_a", psw.stack_a)
    #     print("stack_b", psw.stack_b)
    #     psw.runcmd(cmd)

    # print("stack_a", psw.stack_a)
    # print("stack_b", psw.stack_b)
    animation3()