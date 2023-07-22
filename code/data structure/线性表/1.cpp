#include <iostream>
using namespace std;

#define MaxSize 50
#define ElemType int

// 顺序表定义
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
// 单链表节点定义
typedef struct
{
    int data;
    struct LNode *next;
} LNode;
// 双链表节点定义
typedef struct
{
    int data;
    struct DLNode *prev;
    struct DLNode *next;
} DLNode;

void InitList(SqList &L)
{
    L.length = 0;
}
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i >= L.length)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j + 1] = L.data[j];
    L.data[i] = e;
    L.length++;
    return true;
}
bool ListDelete(SqList &L, int i, ElemType e)
{
    if (i < 1 || i >= L.length)
        return false;
    e = L.data[i];
    for (int j = i; j <= L.length; j++)
        L.data[j] = L.data[j + 1];
    L.length--;
    return true;
}

int main()
{

    SqList L;    // 声明一个顺序表
    InitList(L); // 初始化顺序表
    // 此处省略一些代码 ， 插入几个元素
    ListInsert(L, 3, 3);

    return 0;
}
