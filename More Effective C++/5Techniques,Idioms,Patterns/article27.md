# 要求或禁止对象产生于heap中

## 要求对象产生于heap中
即阻止对象使用new以外的方法产生对象

方法：
- 使dctor为private，此时`Obj O = Obj();`的声明方式不可用
- 将所有的ctor声明为private，注意copy ctor也需要声明为private。然而此方式会影响此class作为基类被继承   
将ctor声明为public，dctor声明为protected可以解决此问题

## 判断某个对象是否位于heap内

### 手动制造flag
```c++
void *Obj::operator new(size_t size){
    onTheHeap = true;
    return ::operator new(size);
}

Obj::Obj(){
    if(!onTheHeap){
        throw HeapConstraintViolation();
    }
    ...
    onTheHeap = false;
}
```
增加static私有成员onTheHeap

此方法的问题在于使用此方法初始化数组的时候会出现问题，因为数组会先分配空间，再多次调用构造函数

### 使用地址判断

根据地址特点，stack的地址表头不断减小，heap不断增加

```c++
bool onHeap(const void *address){
    char tempCurStackAddr;
    return address < &tempCurStackAddr;
}
```
然而，此函数无法区分heap于静态区的地址

### 将地址保存加以判断

```c++
typedef const void* RawAddress;
list<RawAddress> HeapTracked::addresses;

void * HeapTracked::operator new(size_t size){
    void *memPtr = ::operator new(size);
    addresses.push_front(memPtr);
    return memPtr;
}

void HeapTracked::operator delete(void *ptr){
    list<RawAddress>::iterator it = find(addresses.begin(), addresses.end(), ptr);
    if(it!=addresses.end()){
        addresses.erase(it);
        ::operator delete(ptr);
    }
    else
        throw MissingAddress();
}

bool HeapTracked::isOnHeap() const{
    const void* rawAddress = dynamic_cast<const void*>(this);
    list<RawAddress>::iterator it = find(addresses.begin(), addresses.end(), rawAddress);
    return it!=addresses.end();
}
```
原理较为易懂，再new函数中，将新分配的地址存入list中，在delete前进行检查

其中`const void* rawAddress = dynamic_cast<const void*>(this);`的原理是：多重继承或单一虚class的继承会导致对象拥有多个地址  
使用dynamic_cast可以解决这个问题，然而此方式只适用于至少有一个虚函数的class对象

代价：
- 修改了全局空间的new和delete，可能会导致问题
- 记录地址，产生额外开销
## 禁止对象产生于heap中

### 对象直接实例化
重构new和delete，将其设置为private

若也要禁止数组，则重构new[]和delete[]

### 被实例化为derive中的base部分
对于derive，初始化时要将new和delete重构为public，以免继承new和delete导致无法新建derive

### 对象内嵌于class中
此时base的new为private不会有影响，新建对象时调用的是derive::new



