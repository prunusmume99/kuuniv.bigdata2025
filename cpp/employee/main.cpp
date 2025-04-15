#include <iostream>
#include "employee.h"

void printEmployee(Employee *p)
{
    std::cout << "employeeID: " << p->getId() << ", name: " << p->getName() << ", manager: ";
    std::cout << (p->isManager() ? "**Chief**" : p->getManager()->getName()) << std::endl;
}

int main()
{
    Employee e1(1, "Park Jung Seok", NULL);
    Employee e2(2, "Sung Young Ho", &e1);
    Employee e3(3, "Choi Su Gil", &e1);
    Employee e4(4, "Cho Min Sung", &e1);
    Employee e5(5, "Min Byung Hun", &e4);

    // Employee e6 = e1;
    // e2 = e1;

    // Employee employees[10];      // X default constructor is called.
    Employee* pEmployees[10];
    pEmployees[0] = new Employee(1, "Park Jung Seok", NULL);
    pEmployees[1] = new Employee(2, "Sung Young Ho", pEmployees[0]);
    pEmployees[2] = new Employee(3, "Choi Su Gil", pEmployees[0]);
    pEmployees[3] = new Employee(4, "Cho Min Sung", pEmployees[0]);
    pEmployees[4] = new Employee(5, "Min Byung Hun", pEmployees[3]);

    for (int i = 0; i < 5; i++)
    {
        printEmployee(pEmployees[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        delete pEmployees[i];   
    }

    return 0;
}



// #include <iostream>
// #include "employee.h"

// void printEmployee(Employee *p)
// {
//     std::cout << "id : " << p->getId() << " name : " << p->getName() << " manager : ";
//     std::cout << ((p->isManager() ) ? "" : p->getManager()->getName()) << std::endl;
// }

// int main() {
//     // Employee e1(1, String("Park Jung Seok"), NULL);
//     // Employee e2(2, String("Sung Young Ho"), &e1);
//     // Employee e3(3, String("Choi Su Gil"), &e1);
//     // Employee e4(4, String("Choi Min Sung"), &e1);
//     // Employee e5(5, String("Min Byung Hun"), &e4);

//     // Employee e6 = e1;   // 복사 생성자는 안쓰는게 좋을듯
//     // e1 = e2;            // 치환 연산도 안쓰는게 좋을듯

//     // Employee employees[10];     //default constructor is called - 기본 생성자 안만들어서 에러남
//     Employee* pEmployees[10];       // stack에 생성
//     pEmployees[0] = new Employee(1,"Park Jung Seok", NULL);    //heap에 생성
//     pEmployees[1] = new Employee(2,"Sung Young Ho", pEmployees[0]);    //heap에 생성
//     pEmployees[2] = new Employee(3,"Choi Su Gil", pEmployees[0]);    //heap에 생성
//     pEmployees[3] = new Employee(4,"Cho Min Sung", pEmployees[0]);    //heap에 생성
//     pEmployees[4] = new Employee(5, "Min Byung Hun", pEmployees[3]);

//     for (int i = 0; i < 5; ++i)
//     {
//         printEmployee(pEmployees[i]);
//     }
//     for (int i = 0; i < 5; ++i)
//     {
//         delete pEmployees[i];
//     }


//     // std::cout << "id: " << e1.getId() << " " << e1.getName() << std::endl;
//     // std::cout << "id: " << e2.getId() << " " << e2.getName() << std::endl;

//     return 0;
// }
