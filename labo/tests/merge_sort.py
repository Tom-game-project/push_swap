def merge(lst0:iter, lst1:iter,key,comp) -> iter:
    tmp0,tmp1 = next(lst0),next(lst1)
    while not(tmp0 is None and tmp1 is None):
        if tmp0 is None:
            pass
        elif tmp1 is None or comp(key(tmp0), key(tmp1)):
            yield tmp0
            tmp0 = next(lst0)
            continue
        yield tmp1
        tmp1 = next(lst1)
    yield None

def merge2(lst1:list[int], lst2:list[int]) -> list[int]:
    rlist = []

    while lst1 or lst2:
        if lst1 and not lst2:
            pass
        elif lst2 and not lst1:
            pass
        else:        
            

        rlist.append()
    return rlist

def merge_sort(lst:list[int],key = lambda a:a, comp = lambda a, b: a < b) -> iter:
    lst_length = len(lst)
    match lst_length:
        case 0:
            return iter([None])
        case 1:
            return merge(
                iter([lst[0],None]),
                iter([None]),
                key,
                comp
            )
        case 2:
            return merge(
                iter([lst[0],None]),
                iter([lst[1],None]),
                key,
                comp
            )
        case _:
            return merge(
                merge_sort(lst[0:lst_length // 2], key=key, comp = comp),
                merge_sort(lst[lst_length // 2:], key=key, comp = comp),
                key,
                comp
            )


import random
import copy


GREEN = '\033[92m'
RED = '\033[31m'
END = '\033[0m'

def __test_unit(num:int,lst_a:list[int]):
    # lst_a = list(range(100))
    
    random.shuffle(lst_a)
    lst_b = copy.deepcopy(lst_a)

    assert(
        all(
            i==j for i,j in zip(
                [ i for i in merge_sort(lst_a)],
                sorted(lst_b)+[None]
            )
        )
    )
    print(num,"->",GREEN + "Ok!" + END)

def __test00():
    for i,j in enumerate(range(0, 101)):
        __test_unit(i,[k for k in range(j)])


if __name__ == "__main__":
    a = [0,2,5,9,8,7]
    print([i for i in merge_sort(a)])
    print(a)
    print([i for i in merge_sort(a,comp=lambda a,b:a>b)])
    __test00()
    # a = (i for i in [7,8,9,None])
    # b = (i for i in [5,10,None])
    # print(list(merge(a,b)))
