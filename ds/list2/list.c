#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void initList(List *pList)
{
    pList->ptr = malloc(sizeof(Node)); // dummy node.
    // pList->ptr->data=???;
    pList->ptr->next = NULL;
}
//더미노드 만드는이유: 삭제를 위해
void cleanupList(List *pList)
{
    Node*p=pList->ptr;
    while(p ){
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void insertFirstNode(List *pList,int data)
{
    Node *p = malloc(sizeof(Node));
    p->data = data;
    p->next = pList->ptr->next;
    pList->ptr->next = p;
}

void insertNode(List *pList, int prevData, int data)
{
    Node *p = pList->ptr->next;
    while (p){
        if(p->data==prevData){
            break;
        }
        p = p->next;
    }
    if(p ){
        Node *tmp = malloc(sizeof(Node));
        tmp->data = data;
        tmp->next = p->next;
        p->next = tmp;
    }else{
        // X
    }

}

void deleteNode(List *pList, int data)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr; //더미노드를 가리킴

    while (p){
        if (p->data == data)
            break;

        p = p->next;
        p2 = p2->next;
    }
    if(p ){
        p2->next = p->next;
        free(p);
    }/*else{
        //X
    }*/
}

void printList(const List *pList)
{
    Node *p = pList->ptr->next;
    printf("[");
    while(p ){
        printf("%d",p->data);
        printf((p->next) ? ", " : "");
        p=p->next;
    }
    printf("]\n");
}