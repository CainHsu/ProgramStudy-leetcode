//
// Created by xuche on 2019/12/18.
//

#include "iostream"



extern double externTest;

void update(double dt){
    externTest += dt;
    std::cout << "After update: externTest is " << externTest << std::endl;
}