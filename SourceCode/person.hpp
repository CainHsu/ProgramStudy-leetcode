//
// Created by xuche on 2019/12/19.
//

#ifndef PROGRAMSTUDY_LEETCODE_PERSON_HPP
#define PROGRAMSTUDY_LEETCODE_PERSON_HPP

#include "string"
#include "iostream"

class person{
private:
    std::string name;
    int age;
    double height;
public:
    person(){
        name = "Not initialized";
        age = -1;
        height = 0.0;
    }
    person(const std::string & _name){
        name = _name;
    }
    void show_name(){
        std::cout << name;
    }
    ~person(){
        std::cout << "bye~ " << name << std::endl;
    }
};

#endif //PROGRAMSTUDY_LEETCODE_PERSON_HPP
