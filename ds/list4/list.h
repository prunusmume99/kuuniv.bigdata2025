#ifndef LIST_H
#define LIST_H

typedef struct node{
    //int data;
    struct node *next;
} Node;

typedef struct list{
    Node *ptr;
    int eleSize;
}List;

void initList(List *pList, int eleSize);
void cleanupList(List *pList);
void insertFirstNode(List *pList, const void *pData); 
void insertNode(List *pList, const void *pPrevData,const void *pData);
void deleteNode(List *pList, const void *pData); 

void printList(const List *pList, void(*print)(const void*));

#endif