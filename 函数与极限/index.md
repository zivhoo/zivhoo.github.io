# 函数与极限


## 集合

### 名次解释
- 集合：具有某种性质的元素的全体。
- 元素：集合中的每一个。
- 有限集合
- 无限集合

### 集合表示
大写字母表示集合A、B  
用小写字母表示元素a、b  
$$
  元素a属于集合A:a \in A\\
  元素b不属于集合A:b \notin A
$$

  集合表示方法-列举法
$$
  \mathbb{A}=\left\{a_1,a_2,a_3\right\}
$$

集合表示方法-描述法
$$
  \mathbb{M}=\left\{x \middle| x具有的性质p\right\}
$$

特殊集合表示
$$
  实数集合:\\
  \mathbb{R}=\left\{所有的实数\right\}\\

  整数集合:\\
  \mathbb{Z}=\left\{\cdots,-n,\cdots,-2,-1,0,1,2,\cdots,n,\cdots\right\}\\

  自然数集合:\\
  \mathbb{N}=\left\{0,1,2,3,n,\cdots\right\}\\

  正自然数集合:\\
  \mathbb{N^+}=\left\{1,2,3,n,\cdots\right\}\\

  有理数集合:\\
  \mathbb{Q}=\left\{\frac{p}{q}\middle| p\in \mathbb{Z},q \in \mathbb{N^+},p与q互质 \right\}\\
$$

### 集合之间的关系
$$
  A包含在B里\\
  A \subset B,A称为B的子集。\\

  集合相等\\
  A=B \Leftrightarrow A \subset B且， A \supset B\\

  真子集\\
  A \subset B,且 A \neq B,则A就是B的真子集。A \subsetneqq B
$$

空集
$$
  \emptyset
$$

并集
$$
  A \cup B = \left\{x \middle| x \in A\ or\ x \in B \right\}
$$

交集
$$
  A \cap B = \left\{x \middle| x \in A\ and\ x \in B \right\}
$$

差集
$$
  A \setminus B = \left\{x \middle| x \in A\ and\ x \notin B \right\}
$$

余集或称补集
$$
  \overline{A} = A^C = \left\{x \middle| x \notin A \right\}
$$

交换律
$$
A \cup B = B \cup A\\
A \cap B = B \cap A\\
$$

结合律
$$
(A \cup B) \cup C = A \cup (B \cup C)\\
(A \cap B) \cap C = A \cap (B \cap C)\\
$$

分配律
$$
(A \cup B) \cap C = (A \cap C) \cup (B \cap C)\\
(A \cap B) \cup C = (A \cup C) \cap (B \cup C)\\
$$

对偶率
$$
  \overline{(A \cup B)} = \overline{A} \cap \overline{B}\\
  \overline{(A \cap B)} = \overline{A} \cup \overline{B}\\
$$

### 区间与邻域
开区间
$$
  (a,b)=\left\{x \middle| a < x < b\right\}
$$

闭区间
$$
  [a,b]=\left\{x \middle| a \leq x \leq b\right\}
$$

邻域
$$
  以a为中心的一个开区间，就叫做a的邻域。\\
  不强调开区间的半径记做U(a)\\
  强调开区间的半径记做U(a, \delta),点a的\delta邻域\\
  \begin{aligned}
  U(a, \delta) &= \left\{x \middle| x - \delta < x < x + \delta\right\}\\
  &=\left\{x\middle| \left|x - a\right| < \delta \right\}  
  \end{aligned}
$$

点a的去心邻域
$$
\mathring{U}(a, \delta)=\left\{x \middle| 0 < \left|x - a \right| < \delta \right\}
$$

## 映射

有两个非空的集合x和y，存在一个法则f，使得对任一x都有确定的y与之对应，则称f为x到y的一个映射。  
记作
$$
  f:x \longrightarrow y\\

  x:称为定义域，记作：Df\\
$$

$$
x \in \mathbb{X},f(x)=y\\
$$
y称为x的`像`，x称为y的`一个原像`。  

所有的原像叫做`值域`Rf
$$
Rf = \left\{ f(x) \middle| x \in \mathbb{X} \right\}
$$

映射三要素
- 必须要有定义域Df、值域Rf、法则f
- 像唯一，原像不一定
- 满射，Rf=y
- 单射，原像也唯一
- 一一映射，单射+满射  

### 名词解释
- 算子：映射
- 泛函：y是R的一部分
- 变换：自己到自己的映射
- 函数：x属于R,y属于R

### 逆映射与复合映射
单射，从像返回到原像
$$
  f(x)=g,\\
  f^-1(g)=x
$$


