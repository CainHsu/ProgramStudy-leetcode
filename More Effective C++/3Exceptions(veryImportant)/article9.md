# 利用destructors避免泄露资源

```c++
while(statement){
    Obj *O = new Obj();
    O->operation();
    delete O;
}
```
其中delete操作非常有必要，如果不进行，会导致内存泄漏

当O->operation()抛出异常时，会导致其后的语句都不执行，也包括delete语句，因此会导致内存泄漏。

可以使用异常处理避免这一问题：
```c++
while(statement){
    Obj *O = new Obj();
    try{
        O->operation();
    }    
    catch{
        delete O;
        throw "Error.";
    }
    delete O;
}
```
然而，此种操作需要重复书写delete操作，不利于后期维护

可以将delete操作移动到某个局部对象的销毁器中，例如，可以使用智能指针指向局部对象，当智能指针被销毁的时候，就会调用析构函数。

使用智能指针的场景通常是：使用一个对象用以存放必须要被释放的资源
```c++
while(statement){
    unqiue_ptr<Obj> O(new Obj("O"));
    O.get()->operation();
}
```
此时，智能指针被销毁时，其指向的对象也会被销毁，不会造成内存泄露。

然而，智能指针采用单一对象形式的delete，因此数组形式可以从采用vector封装。
