import numpy as np
import matplotlib.pyplot as plt
import matplotlib

# from mpl_toolkits.mplot3d import Axes3D

matplotlib.use('TkAgg')

# データの準備
x = np.array([1, 2, 3, 4, 5])
y = np.array([1, 2, 3, 4, 5])
z = np.zeros_like(x)  # 棒の底の高さ（すべて0に設定）

dx = dy = np.ones_like(x)  # 棒の幅
dz = np.array([1, 2, 3, 4, 5])  # 棒の高さ

# グラフの設定
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 3D棒グラフを描画
ax.bar3d(x, y, z, dx, dy, dz, color='blue', alpha=0.7)

# 軸ラベル
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label (Height)')

# グラフを表示
plt.show()
