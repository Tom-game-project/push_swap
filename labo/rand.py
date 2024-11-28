import random
import sys

def gen(a:int):
    rl = list(range(a))
    random.shuffle(rl)
    return " ".join(map(str,rl))

if __name__ == "__main__":
    print(gen(
        int(sys.argv[1])
    ))
