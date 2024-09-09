import argparse
from labo import optimized_swap,push_swap


# def test05():
#     psw = push_swap([])
#     psw.stack_b = [i for i in range(100)]
#     optimized_swap(psw, 2, 99, len(psw.stack_b))
#     print(psw.stack_b)
#     print("real step", psw.step)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="command for push swap")
    # parser.add_argument("funcname", type = str, help = "swap function name")
    parser.add_argument("index_a",type = int,help = "first index")
    parser.add_argument("index_b",type = int,help = "second index")
    # parser.add_argument("len",type = int, nargs="?",help = "second index")

    args = parser.parse_args()

    psw = push_swap([],print_flag=False)
    psw.stack_b = [i for i in range(10)]
    funcname:str
    step:int
    funcname,step = optimized_swap(psw, args.index_a, args.index_b, len(psw.stack_b))
    print(funcname.center(20,"-"))
    print("step", step)
