import itertools
import pprint

from labo import optimized_swap,instruction,push_swap,swap_stack_b_0,swap_stack_b_1,swap_stack_b_2,swap_checker,swap_stack_b_3

def test00():
    psw = push_swap([2,1,3,6,5,8])
    psw.sa()
    psw.pb()
    psw.pb()
    psw.pb()
    psw.ra()
    psw.rb()
    psw.rra()
    psw.rrb()
    psw.sa()
    psw.pa()
    psw.pa()
    # psw.pa()
    psw.run(instruction.pa)
    print(psw.stack_a)

def checker_test00():
    # Ok
    assert swap_checker([2,1,0], 0, 2)
    assert swap_checker([0,8,2,3,4,5,6,7,1,9], 1, 8)
    assert swap_checker([0,1,5,3,4,2,6,7,8,9], 2, 5)
    # Err
    assert not swap_checker([0,1,2,3,4,5,6,7,8,9], 2, 5)
    assert not swap_checker([0,1,5,3,4,2,6,7,9,8], 2, 5)


def test01():
    psw = push_swap([])
    psw.stack_b = [i for i in range(100)]
    swap_stack_b_0(psw, 97, 99)
    print(list(range(10)))
    print(psw.stack_b)
    print("real step", psw.step)

def test02():
    psw = push_swap([])
    psw.stack_b = [i for i in range(100)]
    swap_stack_b_1(psw, 97, 99, len(psw.stack_b))
    print(list(range(10)))
    print(psw.stack_b)
    print("real step", psw.step)

def test03():
    psw = push_swap([])
    psw.stack_b = [i for i in range(100)]
    swap_stack_b_2(psw, 2, 99, len(psw.stack_b))
    print(list(range(10)))
    print(psw.stack_b)
    print("real step", psw.step)

def test04():
    psw = push_swap([])
    psw.stack_b = [i for i in range(10)]
    swap_stack_b_0(psw, 2, 5)
    print(list(range(10)))
    print(psw.stack_b)
    print("real step", psw.step)

def test05():
    psw = push_swap([])
    psw.stack_b = [i for i in range(100)]
    optimized_swap(psw, 2, 99, len(psw.stack_b))
    print(psw.stack_b)
    print("real step", psw.step)

def test06():
    rlist = []
    for (index_a, index_b) in itertools.combinations((i for i in range(100)), 2):
        # ここで不得意な手を探す
        psw = push_swap([],print_flag = False)
        psw.stack_b = [i for i in range(100)]
        function_name, step = optimized_swap(psw, index_a, index_b, len(psw.stack_b))
        # print(psw.stack_b)
        rlist.append((
            step,
            function_name,
            (index_a, index_b)
        ))
    pprint.pprint(
        sorted(rlist, key= lambda a: a[0])[::-1][:30]
    )

def test07():
    psw = push_swap([5,2,7,3,1,6,4])
    

if __name__ == "__main__":
    test00()
    # test01()
    # test02()
    # test03()
    # test04()
    # test05()
    # test06()