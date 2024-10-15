from enum import Enum,auto


class instruction(Enum):
    sa = auto()
    sb = auto()
    pa = auto()
    pb = auto()
    ra = auto()
    rb = auto()
    rra = auto()
    rrb = auto()

class push_swap:
    def __init__(self, stack_a:list[int], print_flag:bool = True):
        self.stack_a = stack_a
        self.stack_b = []
        self.step = 0
        self.print_flag = print_flag

    def sa(self):
        if 2 <= len(self.stack_a):
            self.stack_a[0],self.stack_a[1] = self.stack_a[1], self.stack_a[0]

    def sb(self):
        if 2 <= len(self.stack_b):
            self.stack_b[0],self.stack_b[1] = self.stack_b[1], self.stack_b[0]

    def pa(self):
        if 0 < len(self.stack_b):
            self.stack_a.insert(0,self.stack_b.pop(0))

    def pb(self):
        if 0 < len(self.stack_a):
            self.stack_b.insert(0,self.stack_a.pop(0))

    def ra(self):
        self.stack_a.append(self.stack_a.pop(0))

    def rb(self):
        self.stack_b.append(self.stack_b.pop(0))

    def rra(self):
        self.stack_a.insert(0,self.stack_a.pop())

    def rrb(self):
        self.stack_b.insert(0,self.stack_b.pop())

    def run(self, command:instruction):
        self.step += 1
        match command:
            case instruction.sa:
                self.sa()
            case instruction.sb:
                self.sb()
            case instruction.pa:
                self.pa()
            case instruction.pb:
                self.pb()
            case instruction.ra:
                self.ra()
            case instruction.rb:
                self.rb()
            case instruction.rra:
                self.rra()
            case instruction.rrb:
                self.rrb()
            case _:
                raise BaseException("Error!")
        if self.print_flag:
            print(command.name)

    def runcmd(self, command:str):
        self.step += 1
        match command:
            case "sa":
                self.sa()
            case "sb":
                self.sb()
            case "pa":
                self.pa()
            case "pb":
                self.pb()
            case "ra":
                self.ra()
            case "rb":
                self.rb()
            case "rra":
                self.rra()
            case "rrb":
                self.rrb()
            # case _:
            #     raise BaseException("Error!")
        # if self.print_flag:
        #     print(command.name)


def swap_checker(data:list, index_a:int, index_b:int):
    # this is test function
    base_iter = list(i for i,_ in enumerate(data))
    x:list[bool] = map(lambda a:a[0] != a[1], zip(base_iter, data))
    count = 0
    for i,j in enumerate(x):
        if j:
            match count:
                case 0:
                    if data[i] == index_b:
                        count += 1
                    else:
                        # 位置は正しい値が違う
                        return False
                case 1:
                    if data[i] == index_a:
                        count += 1
                    else:
                        # 位置は正しい値が違う
                        return False
                case _:
                    # 他の部分に影響している
                    return False
        else:
            pass
    return count == 2

def swap_stack_b_0(ps:push_swap, index_a:int, index_b:int, _:int) -> tuple[str, int]:
    # print("step predict", index_b * 2 + 4)
    for i in range(index_a + 1):
        ps.run(instruction.pa)
    for i in range(index_b - index_a):
        ps.run(instruction.rb)
    ps.run(instruction.pb)
    ps.run(instruction.rrb)
    ps.run(instruction.pa)
    for i in range(index_b - index_a - 1):
        ps.run(instruction.rrb)
    for i in range(index_a + 1):
        ps.run(instruction.pb)
    assert swap_checker(ps.stack_b, index_a, index_b)
    return "swap_stack_b_0", ps.step

def swap_stack_b_1(ps:push_swap, index_a:int, index_b:int, stack_b_length:int) -> tuple[str, int]:
    # print("step predict", 4 * stack_b_length + 2 - 2 * (index_a + index_b))
    a = stack_b_length - index_a - 1
    b = stack_b_length - index_b - 1
    for i in range(b + 1): 
        ps.run(instruction.rrb)
        ps.run(instruction.pa)
    for i in range(a - b): 
        ps.run(instruction.rrb)
    ps.run(instruction.pb)
    ps.run(instruction.rb)
    ps.run(instruction.pa)
    for i in range(a - b - 1):
        ps.run(instruction.rb)
    for i in range(b + 1):
        ps.run(instruction.pb)
        ps.run(instruction.rb)
    assert swap_checker(ps.stack_b, index_a, index_b)
    return "swap_stack_b_1", ps.step

def swap_stack_b_2(ps:push_swap, index_a:int, index_b:int, stack_b_length:int) -> tuple[str, int]:
    # print("step predict", 2 * (index_a + 1) + 6 * (stack_b_length - index_b))
    for i in range(index_a + 1):
        ps.run(instruction.pa)
    for i in range(stack_b_length - index_b):
        ps.run(instruction.rrb)
        ps.run(instruction.pa)
        ps.run(instruction.ra)
    ps.run(instruction.pb)
    ps.run(instruction.rb)
    ps.run(instruction.rra)
    ps.run(instruction.pb)
    for i in range(stack_b_length - index_b - 1):
        ps.run(instruction.rra)
        ps.run(instruction.pb)
        ps.run(instruction.rb)
    for i in range(index_a):
        ps.run(instruction.pb)
    assert swap_checker(ps.stack_b, index_a, index_b)
    return "swap_stack_b_2", ps.step

def swap_stack_b_3(ps:push_swap, index_a:int, index_b:int, _:int) -> tuple[str, int]:
    # print("step predict", 3 * index_b - index_a)
    for i in range(index_a):
        ps.run(instruction.pa)
    for i in range(index_b - index_a - 1):
        ps.run(instruction.sb)
        ps.run(instruction.pa)
    ps.run(instruction.sb)
    ps.run(instruction.rb)
    for i in range(index_b - index_a - 1):
        ps.run(instruction.pb)
    ps.run(instruction.rrb)
    for i in range(index_a):
        ps.run(instruction.pb)
    assert swap_checker(ps.stack_b, index_a, index_b)
    return "swap_stack_b_3", ps.step

def optimized_swap(ps:push_swap, index_a:int, index_b:int, stack_b_length:int) -> tuple[str, int]:
    # t = (f, g)
    # t[0] = f(a:int, b:int, c:int) -> int
    # t[1] = g(ps:push_swap, index_a:int, index_b:int, stack_b_length:int) -> (str, step)
    func_ptrs:tuple = [
        (lambda _index_a,index_b,_stack_b_length:index_b * 2 + 4 ,
         swap_stack_b_0), 
        (lambda index_a,index_b,stack_b_length:4 * stack_b_length + 2 - 2 * (index_a + index_b),
         swap_stack_b_1),
        (lambda index_a,index_b,stack_b_length:2 * (index_a + 1) + 6 * (stack_b_length - index_b),
         swap_stack_b_2), 
        (lambda index_a,index_b,_stack_b_length:3 * index_b - index_a,
         swap_stack_b_3), 
    ]

    swap_func = min(func_ptrs,key=lambda a:a[0](index_a, index_b, stack_b_length))
    function_name,step = swap_func[1](ps,index_a, index_b, stack_b_length)
    return function_name, step 


