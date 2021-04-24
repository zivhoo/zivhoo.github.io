# CGFunctions


## 数学函数
|函数|功能|
|-|-|
|abs(x) |返回输入参数的绝对值|
|acos(x)|反余切函数，输入参数范围为[-1,1]，返回[0,π ]区间的角度值|
|all(x) |如果输入参数均不为0，则返回ture；否则返回flase。&&运算|
|any(x) |输入参数只要有其中一个不为0，则返回true。\|\|运算|
|asin(x)| 反正弦函数,输入参数取值区间为[−1,1]，返回角度值范围为$$ \begin{vmatrix} -\frac{\pi}{2}&\frac{\pi}{2}\end{vmatrix} $$|
|atan(x)|反正切函数，返回角度值范围为,|
|atan2(y,x) |计算y/x 的反正切值。实际上和atan(x)函数功能完全一样，至少输入参数不同。atan(x) = atan2(x, float(1))。|
|ceil(x)| 对输入参数向上取整。例如：ceil(float(1.3)) ，其返回值为2.0|
|clamp(x,a,b)| 如果x 值小于a，则返回a；如果x 值大于b，返回b；否则，返回x。|
|cos(x)| 返回弧度 x的余弦值。返回值范围为[−1,1]|
|cosh(x)| 双曲余弦（hyperbolic cosine）函数，计算x的双曲余弦值。|
|cross(A,B)| 返回两个三元向量的叉积(cross product)。注意，输入参数必须是三元向量！|
|degrees(x)| 输入参数为弧度值(radians)，函数将其转换为角度值(degrees)|
|determinant(m)| 计算矩阵的行列式因子。|
|dot(A,B)| 返回A 和B 的点积(dot product)。参数A 和B可以是标量，也可以是向量（输入参数方面，点积和叉积函数有很大不同）。|
|exp(x)|计算ex的值，e= 2.71828182845904523536|
|exp2(x)|计算2x 的值|
|floor(x)| 对输入参数向下取整。例如floor(float(1.3))返回的值为1.0；但是floor(float(-1.3))返回的值为-2.0。该函数与ceil(x)函数相对应。|
|fmod(x,y)| 返回x/y 的余数。如果y 为0，结果不可预料。|
|frac(x)| Returns the fractional portion of a scalar or each vector component|
|frexp(x, outexp)|将浮点数x 分解为尾数和指数，即x = m* 2^exp，返回m，并将指数存入exp 中；如果x 为0，则尾数和指数都返回0|
|isfinite(x)| 判断标量或者向量中的每个数据是否是有限数，如果是返回true；否则返回false;无限的或者非数据(not-a-number NaN)|
|isinf(x)| 判断标量或者向量中的每个数据是否是无限，如果是返回true；否则返回false;|
|isnan(x)| 判断标量或者向量中的每个数据是否是非数据(not-a-number NaN)，如果是返回true；否则返回false;|
|ldexp(x, n)|计算x ∗2n的值|
|lerp(a, b, f)| 计算(1− f )∗ a + b∗ f 或者a + f ∗(b − a)的值。即在下限a 和上限b 之间进行插值，f 表示权值。注意，如果a 和b 是向量，则权值f必须是标量或者等长的向量。|
|lit(NdotL,NdotH, m)|N 表示法向量；L 表示入射光向量；H 表示半角向量；m 表示高光系数。函数计算环境光、散射光、镜面光的贡献，返回的4 元向量：X 位表示环境光的贡献，总是1.0；Y位代表散射光的贡献，如果N • L < 0，则为 0；否则为N • LZ位代表镜面光的贡献，如果 N • L < 0或者N • H < 0，则位 0；否则为(N • H)m；W 位始终位1.0|
|log(x)| 计算ln ( x)的值，x必须大于 0|
|log2(x)| 计算( )2 log x 的值，x 必须大于0|
|log10(x)| 计算( )10 log x 的值，x 必须大于0|
|max(a, b)| 比较两个标量或等长向量元素，返回最大值。|
|min(a,b)| 比较两个标量或等长向量元素，返回最小值。|
|modf(x, out ip)| 在Cg Reference Manual 中没有查到|
|mul(M, N)| 计算两个矩阵相乘，如果M 为AxB 阶矩阵，N 为BxC 阶矩阵，则返回AxC 阶矩阵。下面两个函数为其重载函数。|
|mul(M, v)| 计算矩阵和向量相乘|
|mul(v, M)| 计算向量和矩阵相乘|
|noise( x)| 噪声函数，返回值始终在0，1 之间；对于同样的输入，始终返回相同的值（也就是说，并不是真正意义上的随机噪声）。|
|pow(x, y)| x^y|
|radians(x)| 函数将角度值转换为弧度值|
|round(x)| Round-to-nearest，或closest integer to x 即四舍五入。|
|rsqrt(x)| X 的反平方根，x 必须大于0|
|saturate(x)| 如果x 小于0，返回0；如果x 大于1，返回1；否则，返回x|
|sign(x)| 如果x 大于0，返回1；如果x 小于0，返回01；否则返回0。|
|sin(x)| 输入参数为弧度，计算正弦值，返回值范围为[−1,1]|
|sincos(float x,out s, out c)|该函数是同时计算x 的sin 值和cos 值，其中s=sin(x)，c=cos(x)。该函数用于“同时需要计算sin 值和cos 值的情况”，比分别运算要快很多!|
|sinh(x)| 计算双曲正弦（hyperbolic sine）值。|
|smoothstep(min,max, x)|值x 位于min、max 区间中。如果x=min，返回0；如果x=max，返回1；如果x 在两者之间，按照下列公式返回数据：
2*( min )3 3*( min )2
max min max min
x − x −
− +
− −|
|step(a, x)| 如果x<a，返回0；否则，返回1。|
|sqrt(x)|求x 的平方根， x ，x 必须大于0。|
|tan(x)| 输入参数为弧度，计算正切值|
|tanh(x)| 计算双曲正切值|
|transpose(M)| M为矩阵，计算其转置矩阵|
