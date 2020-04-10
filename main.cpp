#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <graphics.h>

void ShowData (Node *pnode) {
    for (int i = 0; i < 20; i++) {
        if (pnode -> data.ch[i] != '\0') {
            settextcolor(pnode -> data.color);
            outtextxy(pnode -> data.x, pnode -> data.y - i * 18, pnode -> data.ch[i]);
        }
        else
            break;
    }
}

void MoveData (Node *pnode) {
	pnode->data.y++;
}

int main() {
    initgraph(1200, 800);
    List *pList;    // 指针变量
    ListInit(&pList);   // 创建链表

    while(1) {
        // 创建节点
        Node *pnode = (Node*)malloc(sizeof(Node));
        pnode -> data.x = rand()%1200;  // x 0-1199
        pnode -> data.y = 0;
        pnode -> data.color = RGB(rand() % 255, rand() % 255, rand() % 255);
        int n = rand()%10 + 5;  // 5 - 14
        for (int i = 0; i < n; i++) {
            pnode -> data.ch[i] = rand() % 26 + 65; // 26个大写字母
        }
        pnode -> data.ch[n] = '\0';
        pnode -> pnext = NULL;

        // 添加节点
        InserList(pList, pnode);

        // 显示链表
        TraverList(pList, ShowData);

        // 移动链表
        TraverList(pList, MoveData);
        Sleep(100);
    }
    
    return 0;
}