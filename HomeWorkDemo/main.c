//
//  main.c
//  HomeWorkDemo
//
//  Created by jufn on 2020/5/2.
//  Copyright © 2020 陈俊峰. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"

#define ERROR 0
#define OK 1
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;

typedef Node * LinkList;

Status createLinkList(LinkList *L) {
    int item;
    LinkList temp = NULL;
    LinkList target = NULL;
    printf("请开始输入您想插入的值， 输入0结束");
    while (1) {
        scanf("%d", &item);
        if (item == 0) break;
        
        if (*L == NULL) {
            *L = (LinkList)malloc(sizeof(Node));
            if (*L == NULL) return ERROR;
            (*L)->data = item;
            (*L)->next = *L;
        } else {
            temp = (LinkList)malloc(sizeof(Node));
            if (temp == NULL) return ERROR;
            // 找到最后一个
            for (target = *L; target->next != *L; target=target->next);
            temp->data = item;
            temp->next = target->next;
            target->next = temp;
        }
    }
    return OK;;
}

Status createLinkList2(LinkList *L) {
    LinkList temp = NULL, r = NULL;
    int item;
    printf("请开始输入您想插入的值， 输入0结束:\n");
    while (1) {
        scanf("%d", &item);
        if (item == 0) break;
        if (*L == NULL) {
            *L = (LinkList)malloc(sizeof(Node));
            if (*L == NULL) return ERROR;
            (*L)->data = item;
            (*L)->next = *L;
            r = *L;
        } else {
            temp = (LinkList)malloc(sizeof(Node));
            if (temp == NULL) return ERROR;
            temp->data = item;
            temp->next = r->next;
            r->next = temp;
            r = temp;
        }
    }
    return OK;
}

Status linkListDelete(LinkList *L, int place) {
    int i;
    LinkList target, temp;
    if (place == 1) {
        temp = *L;
        for (target = *L; target->next != *L; target=target->next);
        target->next = temp->next;
        *L = temp->next;
        free(temp);
    } else {
        for (target = *L, i = 1; target->next != *L && i != place -1; target = target->next , i ++);
        temp = target->next;
        target->next = temp->next;
        free(temp);
    }

    return OK;
}

Status linkListInsert(LinkList *L, int place, int num) {
    if (*L == NULL) return ERROR;
    LinkList temp, target;
    // 插在最前面
    if (place == 1) {
        temp = (LinkList)malloc(sizeof(Node));
        if (temp == NULL) return ERROR;
        temp->data = num;
        for (target = *L; target->next != *L; target = target->next);
        temp->next = target->next;
        target->next=temp;
        *L = temp;
    } else {
        int i = 0;
        temp = (LinkList)malloc(sizeof(Node));
        if (temp == NULL) return ERROR;
        temp->data = num;
        for (target = *L, i = 1; target->next != *L && i != place - 1; target = target -> next, i ++);
        if (target == *L && i != place - 1) {
            return -1;
        }
        
        temp->next = target->next;
        target->next = temp;
    }
    return OK;
}

void show(LinkList L) {
    if (L == NULL) {
        printf("这是一个空链表");
        return;
    }
    LinkList temp;
    temp = L;
    
    do {
        printf("%5d", temp->data);
        temp = temp->next;
    } while (temp != L);
    
    printf("\n");
    
}

int main(int argc, const char * argv[]) {
    
    LinkList head = NULL;
    
    int status = createLinkList2(&head);
    printf("创建链表状态%d\n", status);
    show(head);
    
    int place, num;
    
    scanf("%d %d", &place, &num);
    linkListInsert(&head, place, num);
    show(head);
    scanf("%d %d", &place, &num);
    linkListInsert(&head, place, num);
    show(head);
    scanf("%d %d", &place, &num);
    linkListInsert(&head, place, num);
    show(head);
    
    scanf("%d", &place);
    linkListDelete(&head, place);
    show(head);
    scanf("%d", &place);
    linkListDelete(&head, place);
    show(head);

    
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
