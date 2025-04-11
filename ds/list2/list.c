#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// 1.
void initList(List *pList)
{
    pList->ptr = malloc(sizeof(Node)); // dummy node.
    // pList->ptr->data=???;
    pList->ptr->next = NULL;
}
//더미노드 만드는이유: 삭제를 위해 (delete 연산)

//6 클린업리스트도 프린트리스트랑 비슷함
void cleanupList(List *pList)
{
    Node*p=pList->ptr;
    while(p ){
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

// 2. 더미노드 다음에 넣어주는 연산 (1, 3, 4 값 넣기)
void insertFirstNode(List *pList,int data)
{
    Node *p = malloc(sizeof(Node));
    p->data = data;
    p->next = pList->ptr->next; //더미노드가 가리키는 값 (NULL 값 복사)
    pList->ptr->next = p;       //데이터 부분에 p값 넣음
}

//3. 
void insertNode(List *pList, int prevData, int data)
{
    Node *p = pList->ptr->next; //실제 값이 있는 노드 가리킴
    while (p){
        if(p->data==prevData){
            break;
        }
        p = p->next;
    }
    if(p ){
        Node *tmp = malloc(sizeof(Node)); // 값을 찾고 같은걸 찾으면 노드변수를 만듦 tmp
        tmp->data = data;
        tmp->next = p->next;
        p->next = tmp;
    }else{
        // X
    }

}

//4 맨앞에 더미노드가 있고 더미노드의 포인터는 퍼스트노드의 데이터를 가리킴
void deleteNode(List *pList, int data)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr; //더미노드를 가리킴

    while (p){
        if (p->data == data)
            break;

        p = p->next; //각각의 노드를 가리킴
        p2 = p2->next; //p와 같이 나란히 따라감(삭제하려면 앞의것을 알아야해서 p2로 복사)
    }
    if(p ){
        p2->next = p->next;
        free(p);       // p가 가리키는 노드 삭제
    }/*else{
        //X
    }*/
}

//5
void printList(const List *pList)
{
    Node *p = pList->ptr->next;
    printf("[");
    while(p ){
        printf("%d",p->data);
        printf((p->next) ? ", " : "");
        p=p->next;          // 다음 노드 가리킴 맨 마지막엔 널이되면 반복문 빠져나가고 종료됨
    }
    printf("]\n");
}