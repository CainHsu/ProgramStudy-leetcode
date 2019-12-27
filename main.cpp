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

void test(std::vector<int> & vec){
    vec[0] = 0;
}

int & add(int a, int b, int &re){
    re = a + b;
    return re;
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

    int a = 2, b = 3, c;
    add(a, b, c)+=2;
    cout << endl << c;

    person test("toolMan");
    test =  6 + test;
    test.show_all();
    test = 20 - test;
    test.show_all();
    (-test).show_all();
    person & man = test;
    man.nikname;

    return 0;
}




