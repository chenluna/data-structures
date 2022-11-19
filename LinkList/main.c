#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Element;
typedef struct LNode{
    Element date;
    struct LNode* next;
}LNode, *LinkList;

LinkList List_headInsert(LinkList *L) //头插法建立单链表
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    Element x;
    LNode *s;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->next = (*L)->next; s->date = x;
        (*L)->next = s;
        scanf("%d", &x);
    }
    return *L;
}

LinkList List_tailInsert(LinkList *L)  //尾插法建立单链表
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode *s, *r=*L;
    Element x;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->date = x; r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return *L;
}

LNode* GetElem(LinkList L, int i)  //按位置查找
{
    if(i < 0) return NULL;
    if(i == 0) return L;
    LNode *p= L->next;
    int j = 1;
    while(p && (j < i)){
        p = p->next;
        j++;
    }
    if(j < i) {
        printf("查找超出了链表的长度\n");
        return NULL;
    }
    return p;
}

int Link_Length(LinkList L)  //输出链表的长度
{
    if( L->next == NULL)
        return 0;
    int length = 1;
    LNode* p = L->next;
    while(p->next){
        p = p->next;
        ++length;
    }
    return length;
}

bool PrintList(LinkList L)  //逐一顺序打印链表的值
{
    if(L->next == NULL)
    {
        printf("该链表为空表");
        return false;
    }
    LNode* p = L->next;
    do{
        printf("%d\t", p->date);
        p = p->next;
    }while(p != NULL);    //do while 需要加分号
    printf("\n");
    return true;
}

void DestoryLink(LinkList *L, int i)   //按位序删除结点
{
    //0 < i <= Link_length
    if (i <= 0 || i > Link_Length(*L))
        printf("i值不合法");
    LNode *p = (*L)->next; int j = 1;
    while( p && ( j < i-1))  //找到第i-1个结点
    {
        p = p->next;
        ++j;
    }
    LNode *r= p->next;
    p->next = (p->next)->next;
    free(r);
}

void PrintLNode(LinkList L) //对链表进行测试:选择输出某位序的值
{
    LNode* p;
    int i;
    scanf("%d", &i);
    p = GetElem(L, i);
    printf("第%d个位序的值是：%d\n", i, p->date);
}

void Link_Text(LinkList L)   //对链表进行某个测试
{
    //按位序删除某结点的测试
    int i;
    scanf("%d", &i);
    DestoryLink(&L, i);
    PrintList(L);
}

int main(void)
{
    LinkList L;
    List_tailInsert(&L);
    PrintList(L);

    return 0;
}
