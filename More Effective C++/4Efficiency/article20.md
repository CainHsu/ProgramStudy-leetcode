# 协助完成“返回值优化”

```c++
Obj test(){
    Obj temp = Obj("temp");
    return temp;
}

Obj A = O.test();
```
此时调用此函数会使用单参数构造函数与复制构造函数，及其析构函数

优化方案：
```c++
Obj test(){
    return base("temp");
}
```
此时不会调用复制构造函数，减轻系统开销

