# Reference & Pointer

## def
- reference:
```
string & s = string st("temp");
```
- pointer:
```
string *st;
```

## 差异：
- pointer不需要在声明的时候初始化，reference需要
- 使用reference以前不需要进行有效性的判断（是否为nullptr），效率更高
- pointer可以被重新赋值，reference总是指向它最初获得的那个对象

## 使用范围
- pointer：不指向任何对象或在不同时间指向不同对象
- reference：一旦代表了该对象就不再改变




