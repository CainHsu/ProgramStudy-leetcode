# I/O

**cerr**: referred to as the **standard error**, for warnnning and error messages.

**clog**: for general information about the execution of the program.

**Namespaces** allow us to avoid inadvertant collisions between the names we define and uses of those same name in a library.

Reading an unknown number of inputs:
```C++
while(std::cin >> value)
    sum += value;
```
