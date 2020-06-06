# 区别increment/decrement操作的前置和后置形式

## 声明
### 前置
```c++
class Obj{
private:
public:
    Obj& operator++(){
        data++;
        return &this;
    }    
};
```

### 后置
```c++
class Obj{
private:
public:
    const Obj operator++(int){
        Obj temp = *this;
        ++(*this);
        return temp;
    }    
};
```
#### tips
- 为了加以区分，后置对象有一个显式参数int
- 返回const对象的原因是防止i++++操作的出现
- 后置式必须产生一个临时对象，作为返回值使用，略微减低程序效率
- 后置式运算符可以以前置式为基础，从而提升后期维护的效率




