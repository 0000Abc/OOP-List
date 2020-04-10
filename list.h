#pragma once
#include <stdlib.h>

// 数据
struct Data {
    int x;
    int y;
    char ch[20]; // 字符串
    int color;   // 颜色
};

// 节点
struct Node {
    Data data;
    struct Node *pnext;
};

// 链表
struct List {
    Node *pfront;   // 第一个节点的指针
    Node *prear;    // 最后一个节点的指针 
    int count;      // 有多少个节点
};

int     ListInit(List **pplist);
int     IsEmpty (List *plist);
void    InserList(List *plist, Node *pnode);
void    TraverList(List *plist, void(*Traver)(Node* pnode));