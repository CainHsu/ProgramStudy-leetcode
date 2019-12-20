#include <iostream>
#include "SourceCode/DataStructure/ListNode.hpp"
#include "vector"
#include "cmath"
#include "algorithm"
#include "SourceCode/DataStructure/stack.hpp"
#include "stack"
#include "string"
#include "SourceCode/person.hpp"

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

void test(std::vector<int> vec){
    vec[0] = 0;
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

    std::vector<int> tempVec;
    tempVec.emplace_back(1);
    test(tempVec);
    std::cout << tempVec.back();
    return 0;
}




