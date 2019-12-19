# const与指针

- 用法一：
```
int age = 39;
const int * pt = &age;
```
不能使用*pt来修改这个值，但是可以使用
```
age = 20;
```
来修改值。

对于如下情况：
```C++
const int a = 1;
const int * p = &a;    // valid

const int a = 1;
int * p = &a;          // invalid
```
禁止第二种情况的原因很简单，若允许则可以通过*p来修改a的值。

- 用法二：
```
int a = 3;
const int * p = &a;
int * const pp = &a;
```
在最后一个声明中，const的位置不同，这种方式使得pp只能指向a，但允许使用pp来修改a的值。
<br/>中间的声明不允许p来修改a的值，但允许p指向其他地方。
