#include "list.h"
#include <iostream>

Node::Node(int data, Node* next) : data(data), next(next) {}

List::List() {
    head = new Node(-1); // dummy head
}

List::~List() {
    Node* p = head;
    while (p) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
}

void List::insertFirstNode(int data) {
    head->next = new Node(data, head->next);
}

void List::insertNode(int prevData, int data) {
    Node* p = head->next;
    while (p) {
        if (p->data == prevData)
            break;
        p = p->next;
    }
    if (p)
        p->next = new Node(data, p->next);
}

void List::deleteNode(int data) {
    Node* p = head->next;
    Node* prev = head;
    while (p) {
        if (p->data == data)
            break;
        prev = p;
        p = p->next;
    }
    if (p) {
        prev->next = p->next;
        delete p;
    }
}

void List::printList() const {
    Node* p = head->next;
    std::cout << "[";
    while (p) {
        std::cout << p->data;
        if (p->next) std::cout << ", ";
        p = p->next;
    }
    std::cout << "]\n";
}
