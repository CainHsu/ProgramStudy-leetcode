# 明智运用exception specification

对于以下函数：
```c++
void fun() throw(int){
    ...
    // throw已经不适用，通常使用noexcept(false)表示有exception抛出
}
```

## 结论一

不应该将template与exception混用，因为无法知晓template会抛出什么类型的exception

## 结论二

如果A调用了B函数，B无exception specification，那么A也不要设定exception specification

## 结论三

处理系统可能抛出的exception


