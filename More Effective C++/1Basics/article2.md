# C++转型操作符

## 新转型操作符
```C++
- static_cast
- const_cast
- dynamic_cast
- reinterpret_cast
```

## static_cast
```C++
static_cast<type>(expression)
```
与C旧式的转型效果类似

e.g.
```c++
double res = static_cast<double>(first)/intSAecond;
```

## const_cast
用于改变表达式中的常量性(constness)或变易性(volatileness)

e.g.
```c++
void test(int *num);

int a = 0;
const int & b = a;

test(const_cast<int*>(b)); // 函数参数不是const，因此需要将b转换
```


## dynamic_cast
用于执行继承体系中向下转型或跨系转型操作

可以利用dynamic_cast将指向base class obj的指针或引用转型为指向派生类对象的指针或引用，并且获知转型是否成功；  
若转型失败，对象类型返回NULL；引用类型抛出异常

无法应用在缺乏虚函数的类型上

e.g.
```c++
class base{...};
class derived : public base {
public:
    updateViaPtr(derived * BA);
};  

base *BA;
updateViaPtr(dynamic_cast<derived*>(BA));
```

## reinterpret_cast
*与编译平台息息相关，不具备移植性

用于转换函数指针类型

e.g.
```c++
typedef void (*funPtr)();

funPtr funPtrAry[10];

int test();

funPtrAry[0] = reinterpret_cast<funPtr>(&test);
```



