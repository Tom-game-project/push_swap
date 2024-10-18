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


def a_to_b(a:list[int],b:list[int]):
    i = 1
    while len(a) != 0:
        if not b or (a[0] * i < b[0] * i):
            if not b :
                if a[0] * i < a[-1] * i:
                    b.insert(0, a.pop(-1))
                else:
                    b.insert(0, a.pop(0))
            elif a[0] * i < a[-1] * i < b[0] * i:
                b.insert(0, a.pop(-1))
            else:
                b.insert(0, a.pop(0))
        else:
            i *= -1
        print(a,b)

def b_to_a(a:list[int],b:list[int]):
    i = 1
    while len(b) != 0:
        if not a or (b[0] * i < a[0] * i):
            if not a :
                if b[0] * i < b[-1] * i:
                    a.insert(0, b.pop(-1))
                else:
                    a.insert(0, b.pop(0))
            elif b[0] * i < b[-1] * i < a[0] * i:
                a.insert(0, b.pop(-1))
            else:
                a.insert(0, b.pop(0))
        else:
            i *= -1
        print(a,b)

    

def test01():
    random.seed(257)
    b = []
    a = []
    # set number
    a = list(range(10))
    random.shuffle(a)
    a = [7,2,1,5,8,9,6,3,4,10]
    # a = [9,8,6,5,1,2,3,4,7,10]
    print(a)
    il = incr_mapping(a)
    a_to_b(a,b)
    b_to_a(a,b)



if __name__ == "__main__":
    test01()