#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //generic strcpy, strmem strset 때문에

void initList(List *pList, int eleSize)
{
    pList->ptr = malloc(sizeof(Node)); 
    pList->ptr->next = NULL;
    pList->eleSize = eleSize;
}
void cleanupList(List *pList)
{
    Node*p=pList->ptr;
    while(p ){
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}


void insertFirstNode(List *pList,const void *pData)
{
    Node *p = malloc(sizeof(Node) + pList->eleSize);
    //p->pData = pData;
    // 아래거 이 라인처럼 써도 됨 memcpy((unsigned char *)p + sizeof(Node), pData, pList->eleSize);
    memcpy(p + 1, pData, pList->eleSize);

    p->next = pList->ptr->next; 
    pList->ptr->next = p;      
}

void insertNode(List *pList, const void *pPrevpData, const void *pData)
{
    Node *p = pList->ptr->next; 
    while (p){
       //if(p->pData==pPrevpData){
       if(memcmp(p+1, pPrevpData, pList->eleSize) ==0){
            break;
        }
        p = p->next;
    }
    if(p ){
        //Node *tmp = malloc(sizeof(Node)); 
        Node *tmp = malloc(sizeof(Node) + pList->eleSize);
        //tmp->pData = pData;
        memcpy(tmp + 1, pData, pList->eleSize);
        tmp->next = p->next;
        p->next = tmp;
    }else{
        // X
    }

}

void deleteNode(List *pList, const void *pData)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr; 

    while (p){
        //if (p->pData == pData)
        if(memcmp(p+1, pData, pList->eleSize) ==0)
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

void printList(const List *pList, void (*print)(const void *))
{
    Node *p = pList->ptr->next;
    printf("[");
    while(p ){
        //printf("%d",p->data);
        print(p +1);
        printf((p->next) ? ", " : "");
        p=p->next;         
    }
    printf("]\n");
}