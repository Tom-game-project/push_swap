import random
import animation
import copy
from pprint import pprint


def test00():
    random.seed(257)
    b = []
    a = []
    # set number
    a = list(range(10))
    random.shuffle(a)
    # print(a)
    a_copy = copy.deepcopy(a)

    b.append(a.pop(0)) # pb
    i = 0
    ops = []
    while True:
        if len(a) == 0:
            break
        if i%2 == 1: 
            if b[0] < a[0]: # 増加
                b.insert(0,a.pop(0)) # pb
                ops.append("pb")
            elif a[0] < b[len(b) - 1]:
                b.append(a.pop(0)) # pb rb
                ops.append("pb")
                ops.append("rb")
            else:
                i += 1
        else: 
            if b[0] > a[0]: # 減少
                b.insert(0,a.pop(0)) # pb
                ops.append("pb")
            elif a[0] > b[len(b) - 1]:
                b.append(a.pop(0)) # pb rb
                ops.append("pb")
                ops.append("rb")
            else:
                i += 1
        # print("a",a,"\nb",b)
    animation.animation(
        a_copy,
        ops
    )
    print("a",a,"\nb",b)


def incr_mapping(lst:list):
    rlist = []
    i = 0

    while i < len(lst) - 1:
        if lst[i] < lst[i + 1]:
            rlist.append("+")
        else:
            rlist.append("-")
        i += 1
    return rlist

"""
a -> b
"""
def move_stack(a:list[int],b:list[int], f:str,ops:list[str]):
    i = 1
    if a[0] * i < a[-1] * i:
        b.insert(0, a.pop(-1)) # rra pb
        if f == "a": # if  from a
            ops.append("rra")
            ops.append("pb")
        else:
            ops.append("rrb")
            ops.append("pa")
    else:
        b.insert(0, a.pop(0)) # pb
        if f == "a":
            ops.append("pb")
        else:
            ops.append("pa")
    while len(a) != 0:
        if a[0] * i < b[0] * i:
            if a[0] * i < a[-1] * i < b[0] * i:
                b.insert(0, a.pop(-1)) # rra pb
                if f == "a": # if  from a
                    ops.append("rra")
                    ops.append("pb")
                else:
                    ops.append("rrb")
                    ops.append("pa")
            else:
                b.insert(0, a.pop(0)) # pb
                if f == "a":
                    ops.append("pb")
                else:
                    ops.append("pa")
        elif a[-1] * i < b[0] * i:
            b.insert(0, a.pop(-1)) # rra pb
            if f == "a": # if  from a
                ops.append("rra")
                ops.append("pb")
            else:
                ops.append("rrb")
                ops.append("pa")
        elif 1 < len(a) and a[1] * i < b[0] * i:
            b.insert(0, a.pop(1))
            if f == "a":
                ops.append("sa")
                ops.append("pb")
            else:
                ops.append("sb")
                ops.append("pa")
        else:
            i *= -1


def merge_rule(a:list[int], b:list[int],ops:list[str]):
    while not all(map(lambda i:i == "+", incr_mapping(a))):
        move_stack(a,b,"a",ops)
        move_stack(b,a,"b",ops)
    # print("sort -> ok")


def test01():
    # random.seed(257)
    b = []
    a = []
    # set number
    a = list(range(10))
    random.shuffle(a)
    # a = [7,2,1,5,8,9,6,3,4,10]
    # a = [7,2,1,5,8,9,6,3,4]
    # a = [9,8,6,5,1,2,3,4,7,10]
    print(a)
    il = incr_mapping(a)

    for i in range(100):
        b = []
        a = []
        # set number
        a = list(range(10))
        random.shuffle(a)
        merge_rule(a,b)
    print(all(map(lambda i:i == "+", incr_mapping(a))))


def find_nop(ops:list[str]):
    i = 0
    while i < len(ops) - 1:
        if ops[i] == "pa" and ops[i + 1] == "pb":
            return i
        elif ops[i] == "pb" and ops[i + 1] == "pa":
            return i
        i += 1
    return -1

    

def test02():
    b = []
    a = []
    ops = []
    # set number
    a = list(range(157))
    random.shuffle(a)
    copied_a = copy.deepcopy(a)
    print(a)
    # set number
    merge_rule(a,b,ops)
    pprint(ops)
    while (n := find_nop(ops)) != -1:
        print("find nop",n)
        ops.pop(n)
        ops.pop(n)

    # print("step",len(ops))
    animation.animation(copied_a, ops)

def test03():
    steps = []
    for i in range(1000):
        b = []
        a = []
        ops = []
        a = list(range(500))
        random.shuffle(a)
        merge_rule(a,b,ops)
        steps.append(len(ops))

    print("min",min(steps),"max",max(steps),"ave", sum(steps)/len(steps))


if __name__ == "__main__":
    test02() # アニメーション
    # test03()


