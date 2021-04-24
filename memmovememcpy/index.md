# 

title: memmove 和 memcpy的区别

---
memcpy(void *_Dst, const void *_Src, int _Val, size_t _Size);
memmove(void *_Dst, const void *_Src, size_t _MaxCount)

内存重叠的情况下memcpy可能会出错，也可能不会出错
