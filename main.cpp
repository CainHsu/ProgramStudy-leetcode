#include <iostream>
#include "ListNode.hpp"
#include "vector"
#include "cmath"
#include "algorithm"
#include "stack.hpp"
#include "stack"
#include "string"

#define PI 3.1415926

struct ListNode;

bool isValid(std::string s);

template<class T>
inline T swap(T a)
{
    return a*a;
}

int main(int argc, char **argv) {

    std::vector<std::vector<int>> temp;
    temp.emplace_back();
    temp.emplace_back();
    temp[1].emplace_back(2333);
    std::cout << temp[1].size() << std::endl;
    std::cout << temp[1][0] << std::endl;
    return 0;
}




