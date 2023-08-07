#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode*prior,*next;
}DNode,*DLinkList;
//双链表的初始化
bool InitDList(DLinkList &L){
    L=(DNode*)malloc(sizeof(DNode));
    if(L==NULL) return false;
    L->next=NULL;
    L->prior=NULL;
    return true;
}
//判断链表是否为空
bool Empty(DLinkList L,ElemType e){
    if(L->next==NULL) return false;
    else return true;
}
//按值查找，找到第一个数据域为e的节点
DNode*LocateElem(DLinkList L,ElemType e){
    DNode*p=L->next;
    if(!p) return NULL;
    while(p&&p->data!=e){
        p=p->next;
    }
    return p;
}
//在p节点之后插入s
bool InsertNextNode(DNode*p,DNode*s){
    if(p==NULL||s==NULL) return false;
    s->next=p->next;
    if(p->next!=NULL){
        p->next->prior=s;
        p->next=s;
        s->prior=p;
        return true;
    }
}
//在p节点后面插入值是e的节点
bool InsertNextDNode(DNode*p,ElemType e){
    if(p==NULL) return false;
    DNode*q=(DNode*)malloc(sizeof(DNode));
    if(q==NULL) return false;
    q->data=e;
    if(p->next!=NULL){
        q->next=p->next;
        p->next->prior=q;
    }
    q->prior=p;
    p->next=q;
    return true;
}
//删除p节点后继节点
bool DeleteNextNode(DNode*p){
    if(p==NULL) return false;
    DNode*q=p->next;
    if(q==NULL) return false;
    p->next=q->next;
    if(q->next!=NULL)
        q->next->prior=p;
    free(q);
    return true;
}
//删除值为e的结点
bool DeleteNode(DLinkList &L,ElemType e){
    if(L==NULL)  return false;
    DNode*p=L;
    while(p->next->data!=e){
        p=p->next;
    }
    if(p==NULL) return false;
    DNode*q=p->next;
    if(q==NULL) return false;
    p->next=q->next;
    if(q->next!=NULL)
        q->next->prior=p;
    free(q);
    return true;
}
//尾插法
DLinkList List_TailInsert(DLinkList&L,int a[],int n){
    InitDList(L);
    DNode*p=L;
    ElemType x;
    for(int i=0;i<n;i++){
        InsertNextDNode(p,a[i]);
        p=p->next;
    }
    return L;
}
void print(DLinkList L){
    DNode*p=L->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    DLinkList L;
    int a[]={1,2,3,4,5,6,7};
    List_TailInsert(L,a,6);
    printf("尾插法的结果：");
    DeleteNode(L,4);
    print(L);
}
