# 了解virtual functions、multiple inheritance、virtual base classes、RTTI的成本

## 虚函数
### 成本
- 一个vtbl空间
- 对象多耗费一个指针的空间(vptr)  
以上两点可能在分页系统中导致换页的操作更频繁
- 无法同时使用inline  
因为inline属于静态编译，virtual属于动态编译

### 实现
- virtual tables: 由函数指针组成的数组，声明虚函数的class都有**一个**vtbls

```c++
class c1{
public:
    c1();
    virtual void f1();
    virtual void f3();
    virtual ~c1();
    void f2();
};

c1's vtbl:
- c1::~c1()
- c1::f1()
- c1::f3()

class c2 : c1{
public:
    c2();
    virtual ~c2();
    virtual f1();
    virtual void f4();
};

c2's vtbl:
- c2::~c2()
- c2::f1()
- c1::f3()
- c2::f4()
```
非虚函数不在vtbl中  
每个class只有一个vtbl


- virtual table pointers: 指出每一个对象应用于哪一个vtbls

vptr，作为隐藏的成员变量，在声明虚函数的对象中，用来指向该class的vtbl

不论ptr指向谁，编译器会完成以下操作：
- 根据对象的vptr找出vtbl
- 找出被调用的函数在vtbl中的指针
- 调用上一步指针所指向的函数  
```c++
ptr->f1();
equals to:
(*ptr->vptr[i])(ptr)
```

## 多种继承和虚class
多重继承非虚class时，base的成员变量会在每一个derive中复制

将base设置为虚class可以避免这些复制行为，然而虚base会导致对象内隐含的指针增加，指向base

## RTTI
存在于vtbl中，以type_info形式存在，可以通过typeid()获取

class有虚函数时，typeid是动态，反之是静态



