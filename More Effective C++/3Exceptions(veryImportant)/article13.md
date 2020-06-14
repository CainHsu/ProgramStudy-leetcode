# 以by reference方式捕捉exception

## 使用指针的缺陷
### 对象作用域问题
```c++
void fun(){
    Obj O;
    ...
    throw &O;
}
```
离开函数fun()后，对象O将不存在，&O指向空

此时必须使用全局变量或静态变量

### 内存管理问题
当抛出指向heap的指针时需要delete操作，然而指针指向static空间则不需要，使用指针不利于内存管理

### 语言设计矛盾
四个标准的exceptions：
- bad_alloc：operator new无法满足内存需求时发出
- bad_cast：当对一个reference实行dynamic_cast失败时
- bad_typeid：当dynamic_cast施加于null时
- bad_exception：适用于未预期的异常情况

## 使用值传递的缺陷

会引起切割问题，即使用base类型catch derive类型的exception时，会因复制构造函数导致类型转换，造成以下问题：
- 无法使用虚拟函数
- 切割问题：derive转换为base将失去派生部分的成员变量等

## 使用引用传递的优势
- 少复制一次对象
- 避开对象删除问题
- 可以使用虚函数

