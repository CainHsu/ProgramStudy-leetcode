#include <iostream>
#include "SourceCode/DataStructure/ListNode.hpp"
#include "vector"
#include "cmath"
#include "algorithm"
#include "SourceCode/DataStructure/stack.hpp"
#include "stack"
#include "string"
#include "SourceCode/person.hpp"
#include "SourceCode/male.hpp"

#define PI 3.1415926

double externTest = 0.5;
void update(double dt);
void updateStatic();
void updateVec();

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

static int people = 0;
static vector<int> sTest;

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

    person xc("xc");
    male x(18.0, xc);
    xc.show_all();
    x.show_all();
    person & _xc = xc;
    person & _x = x;
    _xc.show_all();
    _x.show_all();
    std::cout << endl;
    person* p_human[3];
    p_human[0] = &xc;
    p_human[1] = &x;
    cout << endl;
    p_human[0]->show_all();
    p_human[1]->show_all();





    return 0;
}




