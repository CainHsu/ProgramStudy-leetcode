# 让构造函数和非成员函数虚化

## 构造函数的虚化

使用场景：根据不同的输入产生不同类型的对象

实现方式：
- virtual copy ctor: 返回一个指针，指向调用者的一个新副本
```c++
class Obj{
public:
    virtual Obj* clone() const = 0;
private:
    ...
};

class UniObj : public Obj{
public:
    virtual UniObj* clone() const{
        return new UniObj(*this);
    }
};
```
由此可见，实现方式之一即为调用真正的copy ctor，也可以保证与原copy ctor操作的一致性

## 将非成员函数虚化
如下函数：
```c++
virtual ostream& operator << (ostream& str) const;
```
由于操作符的左端变量是ostream<<，因此虚化此操作符后，使用方法如下：
```c++
O << cout;
```

改进方式：
```c++
virtual ostream& print(ostream& s) const;
ostream& operator<<(ostream& s, const Obj & O){
    return O.print(s);
}
```
即使用一般的操作符重载函数封装虚化的print函数