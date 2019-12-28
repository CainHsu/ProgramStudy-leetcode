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
    std::string nikname;
    person(){
        name = "Not initialized";
        age = -1;
        height = 0.0;
    }
    explicit person(const std::string & _name){
        name = _name;
        age = -1;
        height = 0.0;
    }
    person(int num){
        age = num;
    }
    void show_name(){
        std::cout << name;
    }
    void show_all();
    ~person(){
        //std::cout << "bye~ " << name << std::endl;
    }
    person operator+(double year) {
        this->age = this->age + year;
        return *this;
    }
    friend person operator+(double year, person & man){
        return (man + year);
    }
    person operator-(double year);
    person operator-();
    friend  person operator-(double year, person & man);
 };

#endif //PROGRAMSTUDY_LEETCODE_PERSON_HPP
