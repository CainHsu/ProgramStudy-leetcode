#include <iostream>
#include <queue>
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


void count(int & N){
    N++;
}

int main(int argc, char **argv) {
    const int aa = 0;
    const_cast<int&>(aa)++;
    count(const_cast<int&>(aa));
    const int& bb = aa;
    count(const_cast<int&>(bb));
    cout << aa << endl;
    static int a = 0;
    a++;
    const int & b = a;
    int & c = a;
    c++;
    const_cast<int&>(b)++;
    count(const_cast<int&>(a));
    cout << a << endl << c;
    return 0;
}




