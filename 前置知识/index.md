# 前置知识


## 常见因式分解

| 展开                        | 分解                |
|-----------------------------|---------------------|
| $a^2 − b^2$                 | $(a+b)(a−b)$        |
| $a^2 + 2ab + b^2$           | $(a+b)(a+b)$        |
| $a^2 − 2ab + b^2$           | $(a−b)(a−b)$        |
| $a^3 + b^3$                 | $(a+b)(a^2−ab+b^2)$ |
| $a^3 − b^3$                 | $(a−b)(a^2+ab+b^2)$ |
| $a^3 + 3a^2b + 3ab^2 + b^3$ | $(a + b)^3$         |
| $a^3 − 3a^2b + 3ab^2 − b^3$ | $(a − b)^3$         |


## 十字相乘
$$
\begin{aligned}
    ?&=12x^2 - 17x + 6\\
    &步骤1:拆分12与6，使得它们交叉相乘的乘积值和为第二项系数\\
    &\begin{vmatrix}
      12&6\\
      &\\
      3&-2\\
      4&-3\\
    \end{vmatrix}\\
    &=(3x - 2)(4x - 3)
  \end{aligned}
$$

## 配方法
$$
  \begin{aligned}
  ?& = 2x^2 + 5x - 3  \\
  &步骤1：前两项提取公因子，使第一项x^2系数为1\\
  & = 2(x^2 + \frac{5}{2}x) - 3\\
  &步骤2：将x^2指数提取到括号外面，同时也去掉第二项的x\\
  & = 2(x + \frac{1}{2} * \frac{5}{2})^2 - 3\\
  & = 2(x + \frac{5}{4})^2 - 3\\
  &步骤3：在末尾减去第二项的幂以及括号前的系数\\
  & = 2(x + \frac{5}{4})^2 - 3 - (2 * (\frac{5}{4})^2)\\
  & = 2(x + \frac{5}{4})^2 - 3 - \frac{25}{8}\\
  & = 2(x + \frac{5}{4})^2 - \frac{49}{8}\\
  \end{aligned}
$$

## 分离常数法
将分子中的x凑成分母形式，分离常数。
$$
\begin{aligned}
  ?&=\frac{2x + 3}{3x - 4}\\
  &步骤1：将分子中的x替换成分母后，原先的2x成了3x，所以乘以\frac{2}{3}\\
  &此时分子中还多减了\frac{8}{3},所以分子中还需要加上\frac{8}{3}\\
  &=\frac{\frac{2}{3} (3x-4)+ \frac{8}{3} + 3}{3x-4}\\
  &=\frac{2}{3} + \frac{17}{3} * \frac{1}{3x-4}\\
\end{aligned}
$$

例2
$$
\begin{aligned}
  ?&=\frac{2x^2 + 3x + 1}{(2x - 1)^2}\\
  &步骤1:将分子x替换成分母（不要带指数）\\
  &\frac{(2x - 1)^2 + 3x + 1}{(2x - 1)^2} = \frac{4x^2 - 2x - 2x + 1^2 + 3x + 1}{(2x - 1)^2} = \frac{4x^2 - 4x +1 + 3x + 1}{(2x - 1)^2}\\
  &=\frac{ \frac{1}{2} * (2x - 1)^2 +2x - \frac{1}{2} + 3x + 1}{(2x - 1)^2} = \frac{ \frac{1}{2} * (2x - 1)^2 + 5x + \frac{1}{2}}{(2x - 1)^2}\\
  &=\frac{1}{2} + \frac{5x + \frac{1}{2}}{(2x - 1)^2}\\
  &把5x替换成分母\\
  &\frac{1}{2} + \frac{(2x - 1) + \frac{1}{2}}{(2x - 1)^2}\\
  &=\frac{1}{2} + \frac{ \frac{5}{2} (2x - 1) + \frac{5}{2} + \frac{1}{2}}{(2x - 1)^2}\\
  &=\frac{1}{2} + \frac{5}{2} * \frac{1}{(2x-1)} + \frac{3}{(2x - 1)^2}\\
  &=\frac{1}{2} + \frac{5}{2} * \frac{1}{(2x-1)} + 3*\frac{1}{(2x - 1)^2}
\end{aligned}
$$

## 绝对值不等式
小于取中间，大于取两边。

例1:
$$
  |2x + 1| < 3\\
  -3 < 2x + 1 < 3\\
  -4 < 2x < 2\\
  -2 < x < 1
$$

例2:
$$
  |1 - 2x| > 5\\
  |2x - 1| > 5\\
  2x - 1 < -5或2x - 1 > 5\\
  x < -2或x > 3
$$

## 二次不等式

- 常见结论
$$
  x^2 < a(a \geq 0) \Longrightarrow |x| < \sqrt{a}\\
  x^2 > a(a \geq 0) \Longrightarrow |x| > \sqrt{a}\\
  x^2 < a(a < 0) \Longrightarrow x \in \empty\\
  x^2 > a(a < 0) \Longrightarrow x \in \mathbb{R}\\
$$

配方法-例1:
$$
  -x^2 + x + 2 < 0
$$

配方法-例2:
$$
  2x^2 + 5x - 3 < 0\\
  2(x^2 + \frac{5}{2}x) - 3 < 0\\
  2(x + \frac{1}{2} * \frac{5}{2})^2 - 3 - 2*(\frac{1}{2} * \frac{5}{2})^2 < 0\\
  2(x + \frac{5}{4})^2 - 3 - \frac{25}{8} < 0\\
  2(x + \frac{5}{4})^2 < \frac{49}{8}\\
  (x + \frac{5}{4})^2 < \frac{49}{16}\\
  \left|x + \frac{5}{4}\right| < \frac{7}{4}\\
  -\frac{7}{4} < x + \frac{5}{4} < \frac{7}{4}\\
  -3 < x < \frac{1}{2}\\
$$

因式分解法-例1:
$$
x^2 - x - 2 < 0
$$

因式分解法-例2:
$$
2x^2 + 5x -3 \geq 0
$$

因式分解法-例3:
$$
-5 \leq 2x^2 + 5x -3 < 0
$$

## 倒数不等式

常见结论
$$
  \begin{aligned}
    (1)&\frac{1}{\pm\infty}=0，
    \frac{1}{0^-}=-\infty，
    \frac{1}{0^+}=+\infty\\

    (2)&x \in (a,b),0 \notin(a,b)\\
    &\Longrightarrow \frac{1}{x} \in(\frac{1}{b},\frac{1}{a})\\

    (3)&x \in(a,b),0 \in(a,b)\\
    &\Longrightarrow x \in(a,0^-) \cup (0^+,b)\\
    &\Longrightarrow \frac{1}{x} \in(\frac{1}{0^-},\frac{1}{a})\cup(\frac{1}{b},\frac{1}{0^+})\\
    &\Longrightarrow \frac{1}{x} \in(-\infty,\frac{1}{a}) \cup (\frac{1}{b},+\infty)
  \end{aligned}\\
$$

## 均值不等式

