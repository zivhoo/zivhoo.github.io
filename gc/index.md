# 垃圾回收


## 三块存储区域 栈、托管堆、非托管堆

## 托管堆的创建

实现了Finalize方法的类，创建其对象时会将对象的指针添加到finalization链表中，当对象成为垃圾时GC会将对象指针从finalization中删除并添加到freachable队列中，之后会启动一个高优先级线程，用来遍历freachable队列并调用每个对象的Finalize方法，至此只是销毁了非托管资源，托管资源需要等到下一次GC工作时才能被销毁。

代龄

NextObjPtr

root

内存压缩



IDispose

using
