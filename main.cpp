#include <iostream>
#include "ListNode.hpp"
#include "vector"
#include "cmath"
#include "algorithm"
#include "stack.hpp"
#include "stack"
#include "string"

#define PI 3.1415926

double externTest = 0.5;
void update(double dt);

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

    std::cout << "externTest:" << externTest << std::endl;
    update(0.2);
    std::cout << "After update:" << externTest << std::endl;

    int value = 0, sum = 0;
    while(std::cin >> value)
        sum += value;
    std::cout << sum;

    return 0;
}




