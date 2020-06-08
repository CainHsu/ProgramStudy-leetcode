# 了解各种不同意义的new和delete 

## new operator和operator new

### new operator
```c++
string *str = new string("test");
```
作用：
- 分配内存用于存放对象
- 调用构造函数，为刚才分配的对象赋予初值

### operator new
```c++
void * operator new(size_t size);

void * rawMemory = operator new(sizeof(double));
```
返回一个指针，指向一块原始的，未设初值的内存

可以重载operator new，但第一个参数必须是size_t

### 两者差异
与malloc相同，operator new的唯一任务就是分配内存， 不调用构造函数

new operator在分配内存的同时调用构造函数

因此，若想做出一个基于堆的对象，必须使用new operator，因为无法直接调用对象初始化需要的构造函数

### 对象构造方式
栈是由编译器自动分配释放 ，存放函数的参数值，局部变量的值，对象的引用地址等。其操作方式类似于数据结构中的栈，通常都是被调用时处于存储空间中，调用完毕立即释放。堆中通常保存程序运行时动态创建的对象，C++堆中存放的对象需要由程序员分配释放，它存在程序运行的整个生命期，直到程序结束由OS释放。
#### 静态
```c++
Obj o();
```
静态建立一个类对象，是由编译器为对象在栈空间中分配内存，通过直接移动栈顶指针挪出适当的空间，然后在这片内存空间上调用构造函数形成一个栈对象。

#### 动态
```c++
Obj *o = new Obj();
```
动态建立类对象，是使用new运算符将对象建立在堆空间中，在栈中只保留了指向该对象的指针。

## placement new
需要再分配好的内存中构建对象，可以使用placement new
```c++
class Obj{
public:
    Obj(string name);
};
Obj * constructInBuffer(void * buffer, int size){
    return new (buffer) Obj("test");
}
```
此函数返回指针，指向一个Obj对象，即将它获得的内存返回。  
当程序运行到shared memory或memory-mapped I/O，此类方法有用，因为在那种运用中，对象必须位于特定地址，或是置于以特殊函数分配的内存中。

（buffer）作为new operator隐式调用operator new时所用

## 分配类操作总结
- 对象产生在堆，使用new operator
- 只分配内存，则使用operator new
- 在已经分配的内存中构造对象，使用placement new
- 在堆中产生自己决定的内存分配方式，需要写自己的operator new，并使用new operator，它会自动调用自己写的operator new


## 删除与内存释放
 ```c++
delete ptr;
```
约等于;
- ptr->~Obj();
- operator delete(ptr);

先析构后释放内存

如果打算处理未分配的内存，应该使用以下方式：
```C++
void * ptr = operator new(sizeof(Obj));
operator delete(ptr)
```
以上操作类似于malloc与free

使用placement new产生对象时，要避免使用delete operator，因为指针来源不确定，delete适用于new产生的对象

## 数组
```c++
string *ptr = new string[10];
delete [] ptr;
```
先调用new分配空间，再使用10次构造函数  
先为每个对象调用析构函数，再释放内存




