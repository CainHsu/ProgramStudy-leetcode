//
// Created by xuche on 2020/2/2.
//

#include "person.hpp"
#include "male.hpp"

male::male(double d, const person & p):person(p){
    length = d;
}

male::male(){
    length = 0.0;
}
