# 

# title: 矩阵

---

行数=列数 叫做方阵

## 矩阵运算

### 加法

A + B

各对应元素相加

### 矩阵数量乘法

k · A

### 矩阵幂运算
    只有方阵才可以幂运算

### 矩阵转置

行变成列，列变成行

矩阵转置的性质

$$
\left(A^T\right)^T=A
$$

$$
\left(A+B\right)^T=A^T+B^T
$$

$$
\left(k\cdot A\right)^T=k\cdot A^T
$$

$$
\left(A\cdot B\right)^T=B^T\cdot A^T
$$

$$
\left(A\cdot B\right)^{-1}=B^{-1}\cdot A^{-1}
$$

$$
\left(A^T\right)^{-1}=\left(A^{-1}\right)^T
$$

## 翻转矩阵

## 错切矩阵

## 旋转矩阵 视频5-2

两角差的余弦公式

$$
\cos\left(a-b\right)=\cos\left(a\right)\cos\left(b\right)+\sin\left(a\right)\sin\left(b\right)
$$

两角差正弦公式

$$
\sin\left(a-b\right)=\sin\left(a\right)\cos\left(b\right)-\cos\left(a\right)\sin\left(b\right)
$$

## 单位矩阵

单位矩阵是一个方阵

$$
I_n=\begin{bmatrix}1&0&\cdots&0\\0&1&\cdots&0\\\cdots&\cdots&\cdots&\cdots\\0&0&\cdots&1\end{bmatrix}
$$

左上角到右下角叫做主对角线

单位矩阵满足乘法的交换律

## 矩阵的逆

$$
当满足AB=BA=I时，则B是A的逆矩阵，记做：B=A^{-1}
$$

可逆矩阵，或者叫非奇异矩阵（必定是方阵）

不可逆矩阵，或者叫奇异矩阵

左逆矩阵和右逆矩阵

如果同时存在左逆矩阵又存在右逆矩阵，那么这两个矩阵必定是相等的且是方阵

如何判断以及计算逆矩阵？

$$
A^0=I\;,A^{-1}=A的逆矩阵\;,A^{-2}={(A^{-1})}^2
$$

## 矩阵的四个视角

+ 二位数据
+ 系统
+ 变换
+ 空间

## 高斯消元法 6.2

1. 矩阵的某行乘以一个常数
2. 矩阵的一行加减另外一行
3. 交互矩阵的两行

## 高斯约旦消元法

1. 前向过程
2. 后向过程

$$
\begin{pmatrix}1&0&0&\left|2\right.\\0&1&0&\left|-3\right.\\0&0&1&\left|-4\right.\end{pmatrix}
唯一解

\begin{pmatrix}1&0&2&\left|3\right.\\0&1&-3&\left|10\right.\\0&0&0&\left|5\right.\end{pmatrix}
无解

\begin{pmatrix}1&0&2&\left|0\right.\\0&1&-3&\left|0\right.\\0&0&0&\left|0\right.\end{pmatrix}
无数解
$$

## 方程个数与未知数个数的关系

| 方程个数<未知数 | 方程个数=未知数 | 方程个数>未知数 |
| -------- | -------- | -------- |
| 无解       | 无解       | 无解       |
|          | 唯一解      | 唯一解      |
| 无数解      | 无数解      | 无数解      |

## 初等矩阵(E)
1. 矩阵的某行乘以一个常数
2. 矩阵的行交换
3. 矩阵的某行加减某行的的若干倍

## 特征值&特征向量
某些向量经过矩阵变换并不会改变向量的方向，只按照一定的倍数缩放向量的长度，那么其中的倍数和向量



### 数学公式在线生成工具

http://www.wiris.com/editor/demo/en/developers
