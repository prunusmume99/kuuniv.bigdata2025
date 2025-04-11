#ifndef LIST_H
#define LIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr);
};

class List {
private:
    Node* head;

public:
    List();                 // 생성자
    ~List();                // 소멸자

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);
    void printList() const;
};

#endif
