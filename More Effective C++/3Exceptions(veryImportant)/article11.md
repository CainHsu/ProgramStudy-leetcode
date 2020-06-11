# 禁止exception流出析构函数

## 调用析构函数的
- 对象在正常状态下被销毁
- 对象被exception处理过程中的栈展开机制销毁

## 原因
- 如果基于exception离开析构函数，而此时有另一个exception处于作用状态，就会调用terminate函数，会将程序结束掉
- 若exception在析构函数抛出，并且没有在当地捕获，会导致析构函数执行不完全

e.g.
```c++
Obj::~Obj(){
    func();
}
```
假设在执行析构函数时，func()抛出异常，然而析构函数中没有catch模块，因而异常会传递到析构函数的调用端。  
假如析构函数是由于某一exception而调用，如下所示。此时就会调用terminate函数，导致程序崩溃。
```c++
try{
    ...
    throw;
}
catch(...){
    O.~Obj();
}
```

## 解决方案
```c++
Obj::~Obj(){
    try{
        func();
    }
    catch(...) {}
}
```
使用特殊的catch结构，阻止exception流出析构函数

这么做的理由：
- 避免terminate函数在exception传播的过程中栈展开的机制被调用
- 确保析构函数完成其该完成的所有事情


