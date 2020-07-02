# 限制某个class所产生的对象个数

## 允许零个或一个对象

```c++
class unique{
private:
    unique();
    unique(const unique& uq);
    ...
public:
    friend unique& theUnique();
};

unique& theUnique(){
    static unique uq;
    return uq;
}

theUnique();
```
使用friend会将theUnique加入全局命名空间，使用static member函数不会有这样的问题，调用方式如下：
```c++
unique::theUnique();
```

也可以将unique class放入一个namespace，可以阻止名称冲突

### 细节讨论
#### class static对象与function static对象
后者只有当function被调用时，对象才被初始化；前者对象的初始化时间不确定

后者的性能代价是每次调用的时候都必须检查对象是否存在，并且后者需要调用者清楚明白什么时候生成对象

#### static对象与inline函数
cpp的编译单元是cpp文件，因此，若将inline与static连用，在较老的版本中，inline使用内部链接，会导致不同文件中产生多个static对象的副本

在较新的版本中，inline为外部链接，不会有这样的问题

## 不同的对象构造状态
base对象可以在三种状态下生存：
- 他自己
- 派生对象的base成分
- 内嵌于较大的对象之中

对于需要产生数个独一无二对象的class，可用如下操作：
```c++
class uni{
public:
    static uni* makeuni();
    static uni* makeuni(const uni& uq);
};
```

## 限制产生有限个数的对象
### 抛出异常
```c++
Unique::Unique(){
    if(num >= 1){
        throw tooManyObjs();
    }
    ...
}
```

### 使用const限制个数

设定`static const int num = 10;`，在构造、复制和析构函数内加入数量计算

## 用来计算对象个数的class
```c++
template<class BeingCounted>
class Counted{
public:
    
protected:
    
private:
    static int numObjs;
    static const int maxNum = 10;
};
```

由于此时Count<Unique>是Unique的一个base class，如果构建对象个数过多，Count<Unique>会抛出异常


