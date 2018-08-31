#include<stdio.h>

//����
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;
//ͷ�巨����
void CreateLinkList(LinkList *CL) {
    Node *rear,*s;
    int c;
    rear = CL;
    scanf("%d",&c);
    while(c != 0) {
        s = (Node *)malloc(sizeof(Node));
        s->data = c;
        rear->next = s;
        rear = s;
        scanf("%d",&c);
    }
    rear->next = CL;

    return 0;
}
//��ʾ����Ԫ��
void ShowLinkList(LinkList L) {
    Node *rear,*s;
    rear = L;
    s = L;
    while(rear->next != s) {
        printf("%d ",rear->data);
        rear = rear->next;
    }
    printf("\n");

    return 0;
}
//ɾ���ն��ڵ�
void Delete(LinkList *L,Node *a) {
    Node *temp,*s;
    temp = L;
    while(temp->next != a) {
        temp = temp->next;
    }
    s = temp->next;
    temp->next = s->next;
}

int main() {
    LinkList a;
    Node *s,*temp;
    int n,count;
    CreateLinkList(&a);
    ShowLinkList(a);

    printf("ָ��ȥ���Ľڵ�:");
    scanf("%d",&n);
    s = a->next;
    for(count = 1;count < n - 1;count++) {
        s = s->next;
    }
    temp = s;
    while(temp->next != s) {
        temp = temp->next;
    }
    Delete(&a,temp);
    ShowLinkList(a);
    return 0;
}
