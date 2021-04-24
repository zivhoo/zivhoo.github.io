# c++ const使用


## 普通常量

`定义`const常量时必须对其初始化，且初始化后不能修改其值；常量与变量可以相互赋值。

```
int n1 = 10;
const int n2 = n1;
n1 = n2;
```

## const与引用
初始化引用或参数传递给引用的各种情况
| 引用  | 变量 | 常量 | 表达式 | 字面值 |
|:---:| ----- | ---- | ---- | ---- |
| 普通引用（int&）| true | false | false | false |
| 常引用（const int&）| true | true | true | true |

```
int n1       = 10;
const int n2 = 20;

int& r1 = n1; //普通引用只能引用变量

// 常量引用可以引用变量、常量、表达式、字面值
const int& r2 = n1;
const int& r3 = n2;
const int& r4 = 3 * 4;
const int& r5 = 10;
```

## const与指针

+ 指针的各种赋值情况

| 指针  | 变量 | 常量 |
|:---:| ----- | ---- |
| 普通指针（int*）| true | false |
| 常量指针（const int*）| true | true |

+ 常量指针与指针常量的区别
常量指针const在*号的左边，表示`指针地址对应的值不可改变`；指针常量const在*号的右边，表示`指针地址不可改变`。

+ 当指针、typedef、const结合使用时，稍有不同。
```
typedef char * StringPtr;
const StringPtr value = "";
// 等价于
char * const value = "";
```

## const与函数参数
+ 普通函数参数（指针和引用除外）不能通过加减const实现函数重载。

## const与类
+ const成员变量：只能在构造函数初始化列表中初始化（只是在对象中是不可变的）。整个类中不变得使用enum
+ const成员函数：函数中不能修改成员变量，也不能调用普通成员函数，却可以被普通成员函数调用，可以和普通成员函数实现重载。

## 用法1
如果某个const变量需要在多个文件中共享，又不能在头文件中初始化，这个时候可以在头文件中用`extern`声明，在cpp中初始化const量

## const_cast

const_cast只能移除指针或引用的const或volatile限定符

dynamic_cast、static_cast、reinterpret_cast
