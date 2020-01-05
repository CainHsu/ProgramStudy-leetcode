//
// Created by xuche on 2019/12/18.
//

#include "iostream"
#include "vector"

using std::vector;

extern double externTest;

static int people = 12;
static vector<int> sTect;
void updateStatic(){
    people++;
}

void update(double dt){
    externTest += dt;
    std::cout << "After update: externTest is " << externTest << std::endl;
}

void updateVec(){
    sTect.emplace_back(0);
}

