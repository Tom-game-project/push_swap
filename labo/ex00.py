from enum import Enum,auto
import itertools
import pprint

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
        sorted(rlist, key= lambda a: a[0])[::-1][:10]
    )

if __name__ == "__main__":
    # test00()
    # test01()
    # test02()
    # test03()
    # test04()
    # test05()
    test06()
