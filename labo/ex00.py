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
    def __init__(self,stack_a:list[int]):
        self.stack_a = stack_a
        self.stack_b = []
        self.step = 0

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
        print(command.name)



def swap_stack_b(ps:push_swap,index_a, index_b):
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
    psw.stack_b = [0,1,2,3,4,5,6,7,8,9]
    swap_stack_b(psw, 2, 6)
    print(list(range(10)))
    print(psw.stack_b)

if __name__ == "__main__":
    # test00()
    test01()