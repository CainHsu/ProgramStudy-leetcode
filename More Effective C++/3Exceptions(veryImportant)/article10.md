# 在constructor内防止资源泄露

现有以下class：
```c++
class image{...};

class Obj{
private:
    string m_name;
    image *m_photo;
public:
    Obj(const string & name, const image & photo) : m_name(name){
        if(photo != "")
            m_photo = new image(photo);
    }
    ~Obj(){
        delete m_photo;
    }
};
```
p.s. delete在删除NULL时是安全的

## 资源泄露原因
当构造函数执行到image的构造函数时，出现exception，则会将控制权返回给Obj的构造函数。此时Obj对象构造不完整，无法调用~Obj()，因此无法删除m_photo已经指向的那个对象，造成资源泄露。

> C++只会析构已经构造完成的对象

也无法使用以下方法：
```c++
Obj *p;
void test(){
    try{
        p = new Obj("name", "image");
    }
    catch(...){
        delete p;
        throw;
    }
    delete p;
}
```
因为除非Obj构造成功，否则p不会被赋值，后面的delete操作也无用。


## 改进方式

```c++
Obj(const string & name, const image & photo) : m_name(name){
    try{
        if(photo != "")
            m_photo = new image(photo);
    }
    catch(...){
        delete m_photo;
        throw;
    }
}
```

由于非指针成员变量（m_name等）使用了链式初始化，这些成员变量会在构造函数被调用之前就初始化。  
因此，Obj析构时，这些成员变量会被销毁。而且，这些成员在构造的过程中产生exception，也会由自己处理，不需要担心。

可以将delete操作封装在class的private部分，减少维护成本。
```c++
class Obj{
public:
    ...
private:
    ...
    inline void cleanUp(){
        delete m_image;
    }
};
```

## 使用*const的情形
> *const是指指针指向的地址不能改变

当成员变量中存在*const时，必须使用链式初始化的方式对其赋值，因此也无法使用try catch语句。

此时可以使用三目运算符：
```c++
Obj(const string & name, const image & photo) : m_name(name), 
                                                m_photo(photo != "" 
                                                    ? new image(photo) : 0)
{}
```

此外，可以将image的构造封装在private中：
```c++
private:
    image* initImage(const string & photo){
        try{
            if(photo != "")
                m_image = new image(photo);    
            else
                return 0;
        }
        catch(...){
            delete m_image;
            throw;
        }
    }
    ...
public:
    Obj(const string & name, const image & photo) : m_name(name), 
                                                    m_photo(initImage(photo))
    {}
```
缺点：维护成本

## 最优方法
将m_image用智能指针表示：
```c++
private:
    ...
    const unique_ptr<image*> m_image;
```
此时，可以直接使用三目运算符对指针赋值，没有内存泄漏的隐患。
```c++
Obj(const string & name, const image & photo) : m_name(name), 
                                                m_photo(photo != "" 
                                                    ? new image(photo) : 0)
{}
```
在此设计中，如果image初始化期间有exception抛出，m_image已经是构造好的对象，因此会被销毁。

同时，当Obj析构时，image也会被自动销毁，即不需要写任何析构函数。

结论：
- 使用智能指针可以免除在构造是由于exception所造成的内存泄漏
- 不需要在析构函数中手动释放资源
- 使得const-ptr与non-const-ptr成员变量有一样简单的处理方式


