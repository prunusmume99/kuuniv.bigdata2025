#include "list.h"
#include <iostream>

int main() {
    List list;  // 생성자에서 초기화됨

    list.insertFirstNode(4);  // [4]
    list.printList();

    list.insertFirstNode(3);  // [3, 4]
    list.printList();

    list.insertFirstNode(1);  // [1, 3, 4]
    list.printList();

    list.insertNode(1, 2);    // [1, 2, 3, 4]
    list.printList();

    list.deleteNode(3);       // [1, 2, 4]
    list.printList();

    // 소멸자에서 cleanup 자동 처리됨
    return 0;
}
