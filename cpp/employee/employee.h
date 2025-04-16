#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "string.h"

class Employee
{
private:
    int id;
    String name;
    Employee *pManager;

    // 사용하지않을 생성자 또는 연산을 private에 선언.
    Employee(const Employee& rhs);
    Employee& operator=(const Employee& rhs);

public:
    Employee(int id, String name, Employee *pManager);
    // ~Employee() {}
    
    // Employee() {}                                                                    is not generated!
    // Employee(const Employee& rhs) { /* memberwise copy */ }                          is not generated!
    // Employee& operator=(const Employee& rhs) { /* memberwise copy */ return *this; } is not generated!

    // Employee* operator&() { return this; }
    // const Employee* operator&() const { return this; }

    int getId();
    String getName();
    Employee *getManager();

    bool isManager();

};

#endif



// #ifndef EMPLOYEE_H
// #define EMPLOYEE_H

// #include "string.h"

// class Employee {
// private:
//     int id;
//     Employee* pManager;
//     String name;

//     // not used
//     Employee(const Employee& rhs);
//     Employee& operator=(const Employee& rhs);

// public:
//     Employee(int id, String name, Employee const* pManager);
//     //Employee() {} - 생성자가 있어서 디폴트 생성자는 안만들어짐

//     //Employee(const Employee& rhs) { memberwise only }     -> private 에 만들면 자동생성 안함
//     //~Employee() {}
//     //Employee& operator=(const Employee& rhs) { memberwise only } -> private 에 만들면 자동생성 안함
//     // Employee* operator&() {return this; }
//     // const Employee* operator&() const { return this;}

//     int getId();
//     String getName();
//     Employee* getManager();

//     //set은 있으면 안됨
//     bool isManager();
// };

// #endif

