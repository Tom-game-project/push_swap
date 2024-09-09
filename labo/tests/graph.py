import numpy as np
import matplotlib.pyplot as plt
import matplotlib

import itertools
from labo import optimized_swap,push_swap
# from mpl_toolkits.mplot3d import Axes3D

matplotlib.use('TkAgg')

COLORS = ['red', 'green', 'blue', 'yellow', 'purple']
FUNC_COLOR = {
    "swap_stack_b_0":COLORS[0],
    "swap_stack_b_1":COLORS[1],
    "swap_stack_b_2":COLORS[2],
    "swap_stack_b_3":COLORS[3],
}

def swap_overall(length:int) -> list[tuple[int, str, tuple[int,int]]]:
    rlist:list[tuple[int, str, tuple[int,int]]] = []
    for (index_a, index_b) in itertools.combinations((i for i in range(length)), 2):
        # ここで不得意な手を探す
        psw = push_swap([],print_flag = False)
        psw.stack_b = [i for i in range(length)]
        function_name, step = optimized_swap(psw, index_a, index_b, len(psw.stack_b))
        # print(psw.stack_b)
        rlist.append((
            step,
            function_name,
            (index_a, index_b)
        ))
     
    # pprint.pprint(
    #     sorted(rlist, key= lambda a: a[0])[::-1][:30])
    return rlist


index_a_list = []
index_b_list = []
steps = []
colors = []
for (step, funcname, (index_a, index_b)) in swap_overall(50):
    # print("-----------------")
    # print(step, funcname, (index_a, index_b))
    index_a_list.append(index_a)
    index_b_list.append(index_b)
    steps.append(step)
    colors.append(FUNC_COLOR[funcname])
    

# データの準備
x = np.array(index_a_list)
y = np.array(index_b_list)
z = np.zeros_like(x)  # 棒の底の高さ（すべて0に設定）

dx = dy = np.ones_like(x)  # 棒の幅
dz = np.array(steps)  # 棒の高さ

# グラフの設定
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 3D棒グラフを描画
ax.bar3d(x, y, z, dx, dy, dz, color=colors, alpha=0.7)

# 軸ラベル
ax.set_xlabel('index_a')
ax.set_ylabel('index_b')
ax.set_zlabel('step')

# グラフを表示
plt.show()
