import random
import animation
import copy


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
    animation.animation4(
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
def move_stack(a:list[int],b:list[int]):
    i = 1
    while len(a) != 0:
        if not b or (a[0] * i < b[0] * i):
            if not b :
                if a[0] * i < a[-1] * i:
                    b.insert(0, a.pop(-1)) # rra pb
                else:
                    b.insert(0, a.pop(0)) # pb
            elif a[0] * i < a[-1] * i < b[0] * i:
                b.insert(0, a.pop(-1)) # rra pb
            else:
                b.insert(0, a.pop(0)) # pb
        else:
            i *= -1
        # print(a,b)


def merge_rule(a:list[int], b:list[int]):
    while not all(map(lambda i:i == "+", incr_mapping(a))):
        move_stack(a,b)
        move_stack(b,a)
    print("sort -> ok")


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




if __name__ == "__main__":
    test01()