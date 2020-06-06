# 对定制的“类型转换”操作符保持警觉

## 隐式类型转换途径
- 单自变量构造函数
- 隐式类型转换操作符

## 单自变量构造函数
### def
以单一自变量成功调用的构造函数：
- 声明拥有单一参数
- 声明拥有多个参数，但除了第一个参数以外都有默认值

### 危害
```c++
class Obj{
private:
public:
    Obj(int N);
    Obj& operator==(const Obj& O) const;
};

Obj a = Obj(1);
int b = 2;

a == b;
```
当class中存在两对象的==运算符重载、单变量构造函数时，若使用可以作为构造函数参数的基础数据类型与对象进习性==操作时，编译器不会报错，并且会使用单变量构造函数生成一个临时对象进行两对象的比较

### 解决方案
使用explicit
```c++
class Obj{
public:
    explicit Obj(int N);
};
```
此时编译器不能通过隐式类型转换调用构造函数

## 隐式类型转换操作符
### def
```c++
class obj{
public:
    operator double() const;
};

Obj O;
double dO = O;
```
### 危害
当类中没有重载`<<`但有类型转换函数时，`cout << O;`可以被强行执行

编译器会先调用转换函数将对象转换为double，再使用<<

### 解决方案
将转换函数写为get函数
```c++
double getData() const{
    return data;
}
```






