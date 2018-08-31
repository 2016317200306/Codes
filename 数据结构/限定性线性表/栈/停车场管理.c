#include <stdio.h>
#define FEIYONG 0.05 //停车费用单价
#define MAXSIZE 5 //停车场容量
#include <stdlib.h>

typedef struct Car {
//结构体：车辆Car
int number;
int inTime;
int outTime;
}Car;

typedef Car User; //用户自定义类型

//--------------通用变量、常量、类型声明------------------

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef int Status;

typedef User SElemType;

//---------------存储表示---------------------

#define STACK_INIT_SIZE 100

#define STACKINCREMENT 10

typedef struct {

SElemType *base;

SElemType *top;

int stacksize;

}SqStack;

//---------------函数原型---------------------

//Status InitStack(SqStack &S);

//构造空栈

//Status DestroyStack(SqStack &S);

//销毁栈S

//Status ClearStack(SqStack &S);

//置空

//Status StackEmpty(SqStack S);

//判空；空：TRUE，不空：FALSE。

//int StackLength(SqStack S);

//返回S的元素的个数，即栈的长度。

//Status GetTop(SqStack S,SElemType &e);

//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR。

//Status Push(SqStack &S,SElemType e);

//插入元素e为新的栈顶元素

//Status Pop(SqStack &S,SElemType &e);

//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR。

//Status StackTraverse(SqStack S,Status ( * visit)());

//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败，则操作失败。

//---------------基本操作---------------------

Status InitStack(SqStack &S) {

//构造空栈

S.base = (SElemType * )malloc(STACK_INIT_SIZE * sizeof(SElemType));

if(!S.base) exit(OVERFLOW);

S.top = S.base;

S.stacksize = STACK_INIT_SIZE;

return OK;

}//InitStack

Status DestroyStack(SqStack &S){

//销毁栈S

free(S.base);

return OK;

}//DestroyStack

Status ClearStack(SqStack &S){

//置空

return OK;

}//ClearStack

//Status ClearStack(SqStack &S);

//置空

Status StackEmpty(SqStack S){

//判空；空：TRUE，不空：FALSE。

if(S.top == S.base) return TRUE;

else return FALSE;

}//QueueEmpty

int StackLength(SqStack S){

//返回S的元素的个数，即栈的长度。

return S.top - S.base;

}

Status GetTop(SqStack S,SElemType &e){

//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR。

if(S.top == S.base) return ERROR;

e = *(S.top-1);

return OK;

}//GetTop

Status Push(SqStack &S,SElemType e){

//插入元素e为新的栈顶元素

if(S.top - S.base >= S.stacksize){//栈满，追加存储空间

S.base = (SElemType *)realloc(S.base,

(S.stacksize + STACKINCREMENT) * sizeof(SElemType));

if(!S.base) exit(OVERFLOW);//存储分配失败

S.top = S.base + S.stacksize;

S.stacksize += STACKINCREMENT;

}

*S.top++ = e;

return OK;

}//Push

Status Pop(SqStack &S,SElemType &e){

//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR。

if(S.top == S.base) return ERROR;

e = * --S.top;

return OK;

}//Pop

Status StackTraverse(SqStack S){//,Status ( * visit)()){

//从栈底到栈顶依次对栈S中每个元素调用函数visit()。一旦visit()失败，则操作失败。

for(SElemType *p = S.base; p < S.top; p++)

printf("%d\n",p->number);

return OK;

}//StackTraverse

typedef int Status;

typedef User QElemType;

//---------------存储表示---------------------

typedef struct QNode {

QElemType data;

struct QNode *next;

}QNode, *QueuePtr;

typedef struct {

QueuePtr front;

QueuePtr rear;

}LinkQueue;

//---------------函数原型---------------------

//Status InitQueue(LinkQueue &Q);

//构造空队列Q

//Status DestroyQueue(LinkQueue &Q);

//销毁队列Q

//Status ClearQueue(LinkQueue &Q);

//置空

//Status QueueEmpty(LinkQueue Q);

//判空；空：TRUE，不空：FALSE。

//int QueueLength(LinkQueue Q);

//返回S的元素的个数，即队列的长度。

//Status GetHead(LinkQueue Q,QElemType &e);

//若队列不空，则用e返回S的队头元素，并返回OK；否则返回ERROR。

//Status EnQueue(LinkQueue &Q,QElemType e);

//插入元素e为新的队尾元素

//Status DeQueue(LinkQueue &Q,QElemType &e);

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR。

//Status QueueTraverse(LinkQueue Q,Status ( * visit)());

//从队头到队尾依次对队列Q中每个元素调用函数visit()。一旦visit()失败，则操作失败。

//---------------基本操作---------------------

Status InitQueue(LinkQueue &Q){

//构造空队列Q

Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));

if(!Q.front) exit(OVERFLOW);

Q.front->next = NULL;

return OK;

}//InitQueue

Status DestroyQueue(LinkQueue &Q){

//销毁队列Q

while(Q.front) {

Q.rear = Q.front->next;

free(Q.front);

Q.front = Q.rear;

}

return OK

;

}//DestroyQueue

//Status ClearQueue(LinkQueue &Q);

//置空

Status QueueEmpty(LinkQueue Q){

//判空；空：TRUE，不空：FALSE。

if(Q.front == Q.rear) return TRUE;

else return FALSE;

}//QueueEmpty

//int QueueLength(LinkQueue Q);

//返回Q的元素的个数，即队列的长度。

Status GetHead(LinkQueue Q,QElemType &e){

//若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR。

if(Q.front == Q.rear) return ERROR;

e = Q.front->next->data;

return OK;

}//GetHead

Status EnQueue(LinkQueue &Q,QElemType e){

//插入元素e为新的队尾元素

QueuePtr p;

p = (QueuePtr)malloc(sizeof(QNode));

if(!p) exit(OVERFLOW);

p->data = e; p->next = NULL;

Q.rear->next = p;

Q.rear = p;

return OK;

}//EnQueue

Status DeQueue(LinkQueue &Q,QElemType &e){

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR。

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

//从队头到队尾依次对队列Q中每个元素调用函数visit()。一旦visit()失败，则操作失败。

for(QueuePtr p = Q.front->next; p !=NULL; p = p->next)

printf("%d\n",p->data.number);

return OK;

}//QueueTraverse

//函数声明部分

void Welcome(); //主选项画面

void GoIn(); //进场部分

int GoOut(); //出场部分

void LookChang(); //查看停车场部分

void LookDao(); //查看便道部分

void LookCopyRight();//查看版权信息

//全局变量声明

SqStack S1,S2; //S1为停车场，S2为暂存的地方

LinkQueue Q; //Q为便道

void Welcome(){

//主选项画面

//clrscr();

printf("****************欢迎使用停车场管理系统****************\n");

printf(" 请选择以下功能：\n\n");

printf(" 1. 车辆到达\n");

printf(" 2. 车辆离去\n");

printf(" 3. 查看停车场内情况\n");

printf(" 4. 查看便道情况\n");

printf(" 5. 退出\n\n");

printf("****************Made by YanJingTu2008*****************\n");

printf("请输入1~6之间的数字选择相应功能：");

}//Welcome

void GoIn(){

//进场部分

Car e;

printf("您选择的是 1.车辆到达\n");

printf("请输入车号：");

scanf("%d",&e.number);

printf("请输入到达时间(格式:HHMM)：");

scanf("%d",&e.inTime);

int i = StackLength(S1);

if(i >= MAXSIZE){ //停车场内已满，车辆在便道等待

printf("\n停车场内已满，请在便道内等待！\n\n");

EnQueue(Q,e);

}else{ //停车场没满，车辆进入

Push(S1,e);

printf("\n车辆%d已于%d时%d分停放在第%d位。\n\n",\

e.number,e.inTime/100,e.inTime-e.inTime/100*100,i+1);

//e.inTime / 100 为车辆进入停车场的时

间（小时）

//e.inTime - e.inTime / 100 * 100 为车辆进入停车场的时间（分钟）

//i+1 为停车位

}

}//GoIn

int GoOut(){

//出场部分

int CarNum; //车号

SElemType *CarID; //车辆在停车场中的位置，指向停车场栈的基址指针

printf("您选择的是 2.车辆离去\n");

if(StackEmpty(S1) == TRUE)

printf("停车场内没有车辆！\n\n"); //看停车场内是否有车

else{

//车辆离开

printf("请输入要离开的车辆的车号：");

scanf("%d",&CarNum);

for(CarID = S1.base; CarID < S1.top; CarID++) //遍历，检查输入的车号

if(CarID->number == CarNum) break;

if(CarID == S1.top) //没有这辆车

printf("对不起，没有这辆车！请检查您输入的车号：%d\n\n",CarNum);

else //找到这辆车了，让其离开停车场

{

printf("车辆%d进入停车场的时间是(格式:HHMM)：%d",CarID->number,CarID->inTime);

printf("\n请输入车辆离开的时间(格式:HHMM)：");

scanf("%d",&CarID->outTime);

if(CarID->outTime <= CarID->inTime)

{

printf("\n时间不正确，离开时间居然会早于到达时间？！\n\n");

return 0;

}

//计算费用，输出费用

int hh1,hh2,mm1,mm2,hh,mm;

float money; //停车金额

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

money = (float)((hh * 60 + mm) * FEIYONG); ////费用四舍五入

printf("您本次的停车费用为 %2.1f 元。谢谢使用。\n\n", money);

//车辆出栈(该车后面的车先出栈并入栈S2暂存)

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

//检查便道中是否有车辆，有的话第一辆车出队列并入栈S1

if(!QueueEmpty(Q))

{

DeQueue(Q,e);

e.inTime = hh2 * 100 + mm2;

Push(S1,e);

//显示提示：便道中的车进入停车场

printf("便道中的第一辆车%d于%d时%d分进入停车场！\n\n",e.number,hh2,mm2);

}

}

}

return 0;

}//GoOut

void LookChang(){

//查看停车场部分

printf("您选择的是 3.查看停车场内情况\n");

StackTraverse(S1);

printf("\n");

}//LookChang

void LookDao(){

//查看便道部分

printf("您选择的是 4.查看便道情况\n");

QueueTraverse(Q);

printf("\n");

}//LookDao

int main(){

//主函数

InitStack(S1); //初始化S1

InitStack(S2); //初始化S2

InitQueue(Q); //初始化Q

while(1){

Welcome();

char i = getchar(); //获取按键(主菜单)

if(i == 10) i = getchar(); //清空字符缓冲区

char i2 = getchar();

while(i2 != 10) i2 = getchar(); //清空字符缓冲区

switch(i){

ca

se '1':

//选择进场

GoIn();break;

case '2':

//选择出场

GoOut();break;

case '3':

//选择查看场内情况

LookChang();break;

case '4':

//选择查看便道情况

LookDao();break;

case '5':

//退出

printf("程序已退出！谢谢使用！\n\n");

exit(0);

break;

default:

//其它

printf("您必须选择1~5之间的数字！\n");

}

}//while(1)

DestroyStack(S1);

DestroyStack(S2);

DestroyQueue(Q);

return 0;

