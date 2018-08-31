#include <stdio.h>
#define FEIYONG 0.05 //ͣ�����õ���
#define MAXSIZE 5 //ͣ��������
#include <stdlib.h>

typedef struct Car {
//�ṹ�壺����Car
int number;
int inTime;
int outTime;
}Car;

typedef Car User; //�û��Զ�������

//--------------ͨ�ñ�������������������------------------

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef int Status;

typedef User SElemType;

//---------------�洢��ʾ---------------------

#define STACK_INIT_SIZE 100

#define STACKINCREMENT 10

typedef struct {

SElemType *base;

SElemType *top;

int stacksize;

}SqStack;

//---------------����ԭ��---------------------

//Status InitStack(SqStack &S);

//�����ջ

//Status DestroyStack(SqStack &S);

//����ջS

//Status ClearStack(SqStack &S);

//�ÿ�

//Status StackEmpty(SqStack S);

//�пգ��գ�TRUE�����գ�FALSE��

//int StackLength(SqStack S);

//����S��Ԫ�صĸ�������ջ�ĳ��ȡ�

//Status GetTop(SqStack S,SElemType &e);

//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR��

//Status Push(SqStack &S,SElemType e);

//����Ԫ��eΪ�µ�ջ��Ԫ��

//Status Pop(SqStack &S,SElemType &e);

//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR��

//Status StackTraverse(SqStack S,Status ( * visit)());

//��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�

//---------------��������---------------------

Status InitStack(SqStack &S) {

//�����ջ

S.base = (SElemType * )malloc(STACK_INIT_SIZE * sizeof(SElemType));

if(!S.base) exit(OVERFLOW);

S.top = S.base;

S.stacksize = STACK_INIT_SIZE;

return OK;

}//InitStack

Status DestroyStack(SqStack &S){

//����ջS

free(S.base);

return OK;

}//DestroyStack

Status ClearStack(SqStack &S){

//�ÿ�

return OK;

}//ClearStack

//Status ClearStack(SqStack &S);

//�ÿ�

Status StackEmpty(SqStack S){

//�пգ��գ�TRUE�����գ�FALSE��

if(S.top == S.base) return TRUE;

else return FALSE;

}//QueueEmpty

int StackLength(SqStack S){

//����S��Ԫ�صĸ�������ջ�ĳ��ȡ�

return S.top - S.base;

}

Status GetTop(SqStack S,SElemType &e){

//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR��

if(S.top == S.base) return ERROR;

e = *(S.top-1);

return OK;

}//GetTop

Status Push(SqStack &S,SElemType e){

//����Ԫ��eΪ�µ�ջ��Ԫ��

if(S.top - S.base >= S.stacksize){//ջ����׷�Ӵ洢�ռ�

S.base = (SElemType *)realloc(S.base,

(S.stacksize + STACKINCREMENT) * sizeof(SElemType));

if(!S.base) exit(OVERFLOW);//�洢����ʧ��

S.top = S.base + S.stacksize;

S.stacksize += STACKINCREMENT;

}

*S.top++ = e;

return OK;

}//Push

Status Pop(SqStack &S,SElemType &e){

//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR��

if(S.top == S.base) return ERROR;

e = * --S.top;

return OK;

}//Pop

Status StackTraverse(SqStack S){//,Status ( * visit)()){

//��ջ�׵�ջ�����ζ�ջS��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�

for(SElemType *p = S.base; p < S.top; p++)

printf("%d\n",p->number);

return OK;

}//StackTraverse

typedef int Status;

typedef User QElemType;

//---------------�洢��ʾ---------------------

typedef struct QNode {

QElemType data;

struct QNode *next;

}QNode, *QueuePtr;

typedef struct {

QueuePtr front;

QueuePtr rear;

}LinkQueue;

//---------------����ԭ��---------------------

//Status InitQueue(LinkQueue &Q);

//����ն���Q

//Status DestroyQueue(LinkQueue &Q);

//���ٶ���Q

//Status ClearQueue(LinkQueue &Q);

//�ÿ�

//Status QueueEmpty(LinkQueue Q);

//�пգ��գ�TRUE�����գ�FALSE��

//int QueueLength(LinkQueue Q);

//����S��Ԫ�صĸ����������еĳ��ȡ�

//Status GetHead(LinkQueue Q,QElemType &e);

//�����в��գ�����e����S�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR��

//Status EnQueue(LinkQueue &Q,QElemType e);

//����Ԫ��eΪ�µĶ�βԪ��

//Status DeQueue(LinkQueue &Q,QElemType &e);

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR��

//Status QueueTraverse(LinkQueue Q,Status ( * visit)());

//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�

//---------------��������---------------------

Status InitQueue(LinkQueue &Q){

//����ն���Q

Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));

if(!Q.front) exit(OVERFLOW);

Q.front->next = NULL;

return OK;

}//InitQueue

Status DestroyQueue(LinkQueue &Q){

//���ٶ���Q

while(Q.front) {

Q.rear = Q.front->next;

free(Q.front);

Q.front = Q.rear;

}

return OK

;

}//DestroyQueue

//Status ClearQueue(LinkQueue &Q);

//�ÿ�

Status QueueEmpty(LinkQueue Q){

//�пգ��գ�TRUE�����գ�FALSE��

if(Q.front == Q.rear) return TRUE;

else return FALSE;

}//QueueEmpty

//int QueueLength(LinkQueue Q);

//����Q��Ԫ�صĸ����������еĳ��ȡ�

Status GetHead(LinkQueue Q,QElemType &e){

//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR��

if(Q.front == Q.rear) return ERROR;

e = Q.front->next->data;

return OK;

}//GetHead

Status EnQueue(LinkQueue &Q,QElemType e){

//����Ԫ��eΪ�µĶ�βԪ��

QueuePtr p;

p = (QueuePtr)malloc(sizeof(QNode));

if(!p) exit(OVERFLOW);

p->data = e; p->next = NULL;

Q.rear->next = p;

Q.rear = p;

return OK;

}//EnQueue

Status DeQueue(LinkQueue &Q,QElemType &e){

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR��

QueuePtr p;

if(Q.front == Q.rear) return ERROR;

p = Q.front->next;

e = p->data;

Q.front->next = p->next;

if(Q.rear == p) Q.rear = Q.front;

free(p);

return OK;

}//DeQueue

Status QueueTraverse(LinkQueue Q){//,Status ( * visit)()){

//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�

for(QueuePtr p = Q.front->next; p !=NULL; p = p->next)

printf("%d\n",p->data.number);

return OK;

}//QueueTraverse

//������������

void Welcome(); //��ѡ���

void GoIn(); //��������

int GoOut(); //��������

void LookChang(); //�鿴ͣ��������

void LookDao(); //�鿴�������

void LookCopyRight();//�鿴��Ȩ��Ϣ

//ȫ�ֱ�������

SqStack S1,S2; //S1Ϊͣ������S2Ϊ�ݴ�ĵط�

LinkQueue Q; //QΪ���

void Welcome(){

//��ѡ���

//clrscr();

printf("****************��ӭʹ��ͣ��������ϵͳ****************\n");

printf(" ��ѡ�����¹��ܣ�\n\n");

printf(" 1. ��������\n");

printf(" 2. ������ȥ\n");

printf(" 3. �鿴ͣ���������\n");

printf(" 4. �鿴������\n");

printf(" 5. �˳�\n\n");

printf("****************Made by YanJingTu2008*****************\n");

printf("������1~6֮�������ѡ����Ӧ���ܣ�");

}//Welcome

void GoIn(){

//��������

Car e;

printf("��ѡ����� 1.��������\n");

printf("�����복�ţ�");

scanf("%d",&e.number);

printf("�����뵽��ʱ��(��ʽ:HHMM)��");

scanf("%d",&e.inTime);

int i = StackLength(S1);

if(i >= MAXSIZE){ //ͣ�����������������ڱ���ȴ�

printf("\nͣ���������������ڱ���ڵȴ���\n\n");

EnQueue(Q,e);

}else{ //ͣ����û������������

Push(S1,e);

printf("\n����%d����%dʱ%d��ͣ���ڵ�%dλ��\n\n",\

e.number,e.inTime/100,e.inTime-e.inTime/100*100,i+1);

//e.inTime / 100 Ϊ��������ͣ������ʱ

�䣨Сʱ��

//e.inTime - e.inTime / 100 * 100 Ϊ��������ͣ������ʱ�䣨���ӣ�

//i+1 Ϊͣ��λ

}

}//GoIn

int GoOut(){

//��������

int CarNum; //����

SElemType *CarID; //������ͣ�����е�λ�ã�ָ��ͣ����ջ�Ļ�ַָ��

printf("��ѡ����� 2.������ȥ\n");

if(StackEmpty(S1) == TRUE)

printf("ͣ������û�г�����\n\n"); //��ͣ�������Ƿ��г�

else{

//�����뿪

printf("������Ҫ�뿪�ĳ����ĳ��ţ�");

scanf("%d",&CarNum);

for(CarID = S1.base; CarID < S1.top; CarID++) //�������������ĳ���

if(CarID->number == CarNum) break;

if(CarID == S1.top) //û��������

printf("�Բ���û��������������������ĳ��ţ�%d\n\n",CarNum);

else //�ҵ��������ˣ������뿪ͣ����

{

printf("����%d����ͣ������ʱ����(��ʽ:HHMM)��%d",CarID->number,CarID->inTime);

printf("\n�����복���뿪��ʱ��(��ʽ:HHMM)��");

scanf("%d",&CarID->outTime);

if(CarID->outTime <= CarID->inTime)

{

printf("\nʱ�䲻��ȷ���뿪ʱ���Ȼ�����ڵ���ʱ�䣿��\n\n");

return 0;

}

//������ã��������

int hh1,hh2,mm1,mm2,hh,mm;

float money; //ͣ�����

hh1 = CarID->inTime / 100;

mm1 = CarID->inTime - hh1 * 100;

hh2 = CarID->outTime / 100;

mm2 = CarID->outTime - hh2 * 100;

if(mm2 - mm1 <0)

{

hh2--;

mm2+=60;

}

hh = hh2 - hh1;

mm = mm2 - mm1;

money = (float)((hh * 60 + mm) * FEIYONG); ////������������

printf("�����ε�ͣ������Ϊ %2.1f Ԫ��ллʹ�á�\n\n", money);

//������ջ(�ó�����ĳ��ȳ�ջ����ջS2�ݴ�)

SElemType e;

Pop(S1,e);

while(e.number != CarID->number || e.inTime != CarID->inTime)

{

Push(S2,e);

Pop(S1,e);

}

while(!StackEmpty(S2))

{

Pop(S2,e);

Push(S1,e);

}

//��������Ƿ��г������еĻ���һ���������в���ջS1

if(!QueueEmpty(Q))

{

DeQueue(Q,e);

e.inTime = hh2 * 100 + mm2;

Push(S1,e);

//��ʾ��ʾ������еĳ�����ͣ����

printf("����еĵ�һ����%d��%dʱ%d�ֽ���ͣ������\n\n",e.number,hh2,mm2);

}

}

}

return 0;

}//GoOut

void LookChang(){

//�鿴ͣ��������

printf("��ѡ����� 3.�鿴ͣ���������\n");

StackTraverse(S1);

printf("\n");

}//LookChang

void LookDao(){

//�鿴�������

printf("��ѡ����� 4.�鿴������\n");

QueueTraverse(Q);

printf("\n");

}//LookDao

int main(){

//������

InitStack(S1); //��ʼ��S1

InitStack(S2); //��ʼ��S2

InitQueue(Q); //��ʼ��Q

while(1){

Welcome();

char i = getchar(); //��ȡ����(���˵�)

if(i == 10) i = getchar(); //����ַ�������

char i2 = getchar();

while(i2 != 10) i2 = getchar(); //����ַ�������

switch(i){

ca

se '1':

//ѡ�����

GoIn();break;

case '2':

//ѡ�����

GoOut();break;

case '3':

//ѡ��鿴�������

LookChang();break;

case '4':

//ѡ��鿴������

LookDao();break;

case '5':

//�˳�

printf("�������˳���ллʹ�ã�\n\n");

exit(0);

break;

default:

//����

printf("������ѡ��1~5֮������֣�\n");

}

}//while(1)

DestroyStack(S1);

DestroyStack(S2);

DestroyQueue(Q);

return 0;

