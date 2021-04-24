# 

title: 智能指针
---
## std::auto_ptr<Class> p(new Class())

### 缺点
+ 当函数参数时不能引用计数加1
+ 不能和操作符new[] 一起使用
+ 不能和标准容器一起使用

## std::shared_ptr
