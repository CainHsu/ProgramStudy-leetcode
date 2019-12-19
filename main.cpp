#include <iostream>
#include "ListNode.hpp"
#include "vector"
#include "cmath"
#include "algorithm"
#include "stack.hpp"
#include "stack"
#include "string"
#include "person.hpp"

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

class person;

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

    {
        person xc("xc");
        xc.show_name();
        std::cout << std::endl;
    }

    return 0;
}




