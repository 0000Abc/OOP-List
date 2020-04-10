#include "list.h"

// 初始化链表 成功返回1 失败返回0

int ListInit(List **pplist) {    // pplist -> pList
    *pplist = (List*)malloc(sizeof(List));

    if (NULL == *pplist)
        return 0;
    else {
        (*pplist) -> pfront = NULL;
        (*pplist) -> prear = NULL;
        (*pplist) -> count = 0;
    }
    return 1;
}

// 判断链表是否为空
int IsEmpty (List *plist) {
    if (plist -> count == 0)
        return 1;
    else
        return 0;
}

// 在 plist 这个链表中插入 pnode 的节点
void InserList(List *plist, Node *pnode) {
    // 尾插法
    if (IsEmpty(plist))
        plist -> pfront = pnode;
    else 
        plist -> prear -> pnext = pnode;

    plist -> prear = pnode;
    plist -> count++;
}

// 遍历链表：留接口
// 遍历 plist 这个链表
// 函数指针
/*
    指向函数的指针
    指针：Traver
    指向 返回值类型为 void, 参数为 Node*
*/
void TraverList(List *plist, void(*Traver)(Node* pnode)) {
    Node *ptemp = plist -> pfront;  // ptemp 指向第一个节点
    int listsize = plist -> count;  // 有几个节点

    while (listsize)
    {
        Traver(ptemp);
        ptemp = ptemp ->pnext;
        listsize--;
    }
    
}
