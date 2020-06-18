# 考虑使用lazy evaluation

def: 直到下一刻就需要的地步才进行相关的运算或分配空间

## Reference Counting

```c++
string s1 = "hello";
string s2 = s1;
```
此种方式立即为s2分配空间

若s2的作用仅仅是作为s1的副本并且不进行任何修改呢？

此时可以让s2分享s1的值而不是制作一个副本

当且仅当s2要做一些修改的时候，如:`s2.convertToUpperCase()`时才为s2生成副本

## 区分读写

```c++
cout << s[3];
s[3] = 'c';
```
第一个操作为读取，第二个为修改

做修改时可能需要先为s做一个副本，然而运算符[]无法知晓我们的操作是读取或修改

## Lazy Fetching

处理一些空间较大的对象时，取出此对象的所有数据所需的时间较长，尤其是在网络通信上。

可以将本地对象的成员变量设置为指针，使用成员函数从网络中读取成员变量的内容

```c++
class Obj{
private:
    ObjectID oid;
    mutable string* name; // mutable: 变量在const函数中也可以被修改
    ...
public:
    Obj() : oid(id), name(0),...{}
    const string & readName() const{
        if(name == 0)
            read name from Internet and make *name point to it
        return *name;
    }
};
```
此对象中的ctor负责将每个指针初始化为null

然而使用指针作为成员变量还涉及delete操作以及exception处理等问题，此处也可以使用智能指针处理

## Lazy Expression Evaluation
```c++
matrix<int> m1(100, 100);
matrix<int> m2(100, 100);

matrix<int> m3 = m1 + m2;
```

此时可以先不进行m3的计算，而是将m3的表达式记录，可以使用两个矩阵指针和一个操作符enum构成  
也可以在m3中存储m1，m2的weak_ptr
```c++
cout << m3[4];
```
当需要m3的值时，才进行相关的运算
```c++
m3 = m1 + m2;
m1 = m4;
```
同时，当构成m3的元素发生改变时，也需要进行相关的操作，如创建副本或修改m3中存储的表达式等

因此，使用Lazy Expression Evaluation的一个重要问题就是需要对class进行大量的维护，包括赋值、复制、加法、减法等操作。

