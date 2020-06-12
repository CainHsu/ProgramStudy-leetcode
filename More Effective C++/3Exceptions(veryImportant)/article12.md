# 了解抛出一个exception、传递一个参数与调用一个虚函数之间的差异

## 差异一
### 1
```c++
void test(){
    try{
        ...
        throw O;
    }
}
```
由于离开test()，局部对象O就会被析构。  
因此，以对象传递exception时，使用引用或值传递都会发生对象的复制。

因此，即使使用引用传递的方式传递exception，再catch中也无法修改原始的对象。  
因而，传递exception往往比传递参数慢。

### 2
```c++
void test(){
    derive D;
    ...
    base & B = D;
    throw B;
}
```
由于此时throw的时静态类型为base的引用，因此exception的复制也为base类型。

### 3
```c++
catch(base & B){
    ...
    throw;
}
```
此时，会将exception重新抛出，没有复制行为。即使传进来的是derive，也不会因赋值操作变为base类型

### 4
```c++
catch (base B) ...
catch (base & B) ...
catch (base *B) ...
```

- 使用值传递，会产生两个副本，第一个为：exception传递产生的临时对象，第二个为：将临时对象复制到B
- 使用引用传递，会产生一个副本：exception传递产生的临时对象，不会因复制对象产生另一个副本
- 使用指针传递，不会产生副本，但要注意不要抛出局部指针，以免传递野指针

## 差异二

调用者和抛出者之间存在的类型吻合规则（没有自动类型转换）

exception中仅有两种类型转换：
- 针对base写的catch语句可以处理derive的exception
- 有形指针转换为无形指针，即以const void*指针而设计的catch语句可以捕捉任何指针类型的exception

## 差异三
catch依据出现顺序做匹配尝试，虚函数采用的是最佳吻合的匹配策略



