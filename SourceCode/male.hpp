//
// Created by xuche on 2020/2/2.
//

#ifndef PROGRAMSTUDY_LEETCODE_MALE_HPP
#define PROGRAMSTUDY_LEETCODE_MALE_HPP

#include "person.hpp"

class male : public person{
private:
    double length;
public:
    male(double d, const person & p);
    male();
    void show_all_male();
    void showTest(const person & p);

    virtual void show_all();
};

#endif //PROGRAMSTUDY_LEETCODE_MALE_HPP
