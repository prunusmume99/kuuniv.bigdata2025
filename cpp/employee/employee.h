#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "string.h"

class Employee {
private:
    int id;
    Employee* pManager;
    String name;

    // not used
    Employee(const Employee& rhs);
    Employee& operator=(const Employee& rhs);

public:
    Employee(int id, String name, Employee const* pManager);
    //Employee() {} - 생성자가 있어서 디폴트 생성자는 안만들어짐

    //Employee(const Employee& rhs) { memberwise only }     -> private 에 만들면 자동생성 안함
    //~Employee() {}
    //Employee& operator=(const Employee& rhs) { memberwise only } -> private 에 만들면 자동생성 안함
    // Employee* operator&() {return this; }
    // const Employee* operator&() const { return this;}

    int getId();
    String getName();
    Employee* getManager();

    //set은 있으면 안됨
    bool isManager();
};

#endif
