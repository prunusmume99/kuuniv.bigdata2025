#include "employee.h"

Employee::Employee(int id, String name, Employee const* pManager) {
    this->id = id;
    this->name = name;
    this->pManager = const_cast<Employee*>(pManager);  // const 제거
}

int Employee::getId() {
    return this->id;
}

String Employee::getName() {
    return this->name;
}

Employee* Employee::getManager() {
    return this->pManager;
}

bool Employee::isManager() {
    return this->pManager == nullptr;
}
