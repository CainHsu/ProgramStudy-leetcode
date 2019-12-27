//
// Created by xuche on 2019/12/25.
//

#include "person.hpp"

person person::operator-(double year){
    this->age -= year;
    return *this;
}

person person::operator-(){
    this->age = -this->age;
    return *this;
}

person operator-(double year, person & man){
    return (-man + year);
}

using std::cout;
using std::endl;
void person::show_all(){
    cout << "Name is: " << name << endl;
    cout << "Age is: " << age << endl;
    cout << "Height is: " << height << endl;
}
