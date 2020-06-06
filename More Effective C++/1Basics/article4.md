# 非必要不提供default constructor

有很多对象，如果没有外类信息就没法完成一个初始化的动作。

因此，必须有某些外来信息才能生成对象的class，不需要拥有default constructor

## 缺乏默认构造函数的问题

### 问题1
在产生数组时，无法为数组中的对象指定构造函数自变量  
e.g.
```c++
Obj Objs = new Obj[10];
Obj Objs[10]; // 错，无法调用，需要默认构造函数
```

#### 方法1
使用non-heap数组，此方法无法延申至heap数组
```c++
int ID1, ID2, ID3;

Obj Objs[] = {
    Obj[ID1],
    Obj[ID2],
    Obj[ID3]    
};
```

#### 方法2
更一般的方法是使用指针数组
```c++
typedef Obj* OBJ;

OBJ *OBJ_P_Ary = new OBJ[10];
```

此种方式有几个缺点：
- 需要将数组的所有对象删除
- 需要的内存空间较大

##### 过度分配内存解决方法
先为此数组分配raw memory

使用placement new，见article8
```c++

```

### 问题2
不适用于模板类

