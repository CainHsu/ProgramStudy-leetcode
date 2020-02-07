//
// Created by xuche on 2020/2/2.
//

#include "person.hpp"
#include "male.hpp"

male::male(double d, const person & p):person(p), length(d){
    //length = d;
}

male::male(){
    length = 0.0;
}

void male::show_all_male() {
    show_all();
    std::cout << "Length is: " << length << std::endl;
}

void male::show_all() {
    std::cout << "This is male.";
}