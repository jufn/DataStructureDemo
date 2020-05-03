//
//  main.c
//  TwoLinkList
//
//  Created by jufn on 2020/5/3.
//  Copyright © 2020 陈俊峰. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct Node {
    struct Node *prior;
    struct Node *next;
    ElemType data;
} Node;

typedef Node * LinkList;

Status createLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (*L == NULL) return ERROR;
    (*L)->data = -1;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    LinkList p = *L;
    
    // 拼接
    for (int i = 0; i < 10; i ++) {
        LinkList temp = (LinkList)malloc(sizeof(Node));
        if (temp == NULL) return ERROR;
        temp->data = i;
        temp->prior = p;
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    return OK;
}

void display(LinkList L) {
    if (L == NULL || L->next == NULL) {
        printf("这是一个空链表");
    }
    LinkList temp = L->next;
    while (temp != NULL) {
        printf("%5d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status insertLink(LinkList *L, int place, int num) {
    if (*L == NULL || (*L)->next == NULL) {
        printf("这是一个空的双向链表");
        return ERROR;
    }
    
    LinkList temp = (LinkList)malloc(sizeof(Node));
    if (temp == NULL) return ERROR;
    temp->data = num;
    temp->next = NULL;
    temp->prior = NULL;
    
    LinkList p = (*L);
    int i = 1;
    while (p != NULL && i < place) {
        p = p->next;
        i ++;
    }
    if (p == NULL) {
        printf("插入越界. \n");
        return ERROR;
    }
    
    if (p->next == NULL) {
        temp->prior = p;
        p->next = temp;
    } else {
        temp->next = p->next;
        p->next->prior = temp;
        
        p->next = temp;
        temp->prior = p;
    }
    return OK;
}

Status linkDelete(LinkList *L, int place) {
    if (*L == NULL || (*L)->next == NULL) {
        printf("这是一个双向链表\n");
        return ERROR;
    }
    LinkList d = (*L)->next;
    int i = 1;
    while (d != NULL && i < place) {
        d = d->next;
        i ++;
    }
    if (d == NULL) {
        printf("beyond bounds\n");
        return ERROR;
    }
    if (d->next != NULL) {
        d->next->prior = d->prior;
    }
    d->prior->next = d->next;
    free(d);
    
    if ((*L)->next == NULL) {
        free(*L);
        *L = NULL;
    }
    return OK;
}

Status replaceList(LinkList *L, int place, ElemType e) {
    if (*L == NULL || (*L)->next == NULL) {
        printf("这是一个空的双向链表");
        return ERROR;
    }
    
    LinkList p = (*L)->next;
    int i = 1;
    while (p != NULL && i < place) {
        i ++;
        p = p -> next;
    }
    if (p == NULL ) {
        printf("beyond bounds\n");
        return ERROR;
    }
    p->data = e;
	return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    LinkList head = NULL;
    createLinkList(&head);
    display(head);
    
    int place, num;
    scanf("%d %d", &place, &num);
    insertLink(&head, place, num);
    display(head);
    scanf("%d %d", &place, &num);
    insertLink(&head, place, num);
    display(head);
    scanf("%d %d", &place, &num);
    insertLink(&head, place, num);
    display(head);
    
    printf("请输入想要删除第几位:\n");
    scanf("%d", &place);
    linkDelete(&head, place);
    display(head);
    scanf("%d", &place);
    linkDelete(&head, place);
    display(head);
    scanf("%d", &place);
    linkDelete(&head, place);
    display(head);
    
    return 0;
}
