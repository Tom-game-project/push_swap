import argparse
from labo import push_swap,swap_stack_b_0,swap_stack_b_1,swap_stack_b_2,swap_stack_b_3


if __name__ == "__main__":
    # stack b length -> 100
    parser = argparse.ArgumentParser(description="command for push swap")
    # parser.add_argument("funcname", type = str, help = "swap function name")
    parser.add_argument("index_a",type = int,help = "first index")
    parser.add_argument("index_b",type = int,help = "second index")
    # parser.add_argument("len",type = int, nargs="?",help = "second index")
    func_iter = [
        swap_stack_b_0,
        swap_stack_b_1,
        swap_stack_b_2,
        swap_stack_b_3,
    ]
    args = parser.parse_args()

    for func in func_iter:
        psw = push_swap([],print_flag=False)
        psw.stack_b = [i for i in range(100)]
        funcname:str
        step:int
        funcname,step = func(psw, args.index_a, args.index_b, len(psw.stack_b))
        print(funcname.center(20,"-"))
        print("step", step)

    