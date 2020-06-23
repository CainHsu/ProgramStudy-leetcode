# 利用重载技术避免隐式类型转换

## 问题
```c++
class Obj{
private:
    int m_val;
public:
    Obj(int val);
    Obj operator+(const Obj& O) const;
};
```
由于构造函数没有explicit，此时调用`int + Obj`时会先调用默认构造函数，将int转换为Obj，再调用重载的+运算符

此种方法会加大程序的开销

## 解决方案
```c++
class Obj{
private:
    int m_val;
public:
    Obj(int val);
    Obj operator+(const Obj& O) const;
    Obj operator+(int val) const;
    friend Obj operator+(int val, const Obj& O) const;
};
```
此时需要穷举所有的+运算符可能性，使用友元调用其他的接口，可以减少开发成本
