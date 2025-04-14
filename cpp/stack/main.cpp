#include <iostream>
#include "list.h"

int main() {
    List list;

    list.insertFirstNode(4);     // [4]
    list.insertFirstNode(3);     // [3, 4]
    list.insertFirstNode(1);     // [1, 3, 4]
    list.insertNode(1, 2);       // [1, 2, 3, 4]
    list.deleteNode(3);          // [1, 2, 4]

    list.printList();            // 출력: [1, 2, 4]

    return 0;
}
