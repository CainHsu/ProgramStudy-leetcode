# 考虑以操作符复合形式（op=）取代其独身形式（op）

```c++
Obj& operator+=(const Obj & O){
    ...
    return *this;
}

Obj operator+(const Obj & O) const{
    ...
    return Obj(this->val + O.val);
}
```
由此可见，使用A += B的开销要小于A = A + B的开销


