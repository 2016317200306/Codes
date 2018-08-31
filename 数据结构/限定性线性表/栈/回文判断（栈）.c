#include <string.h>
#include <stdio.h>
#define MAXSIZE 100
typedef struct {
  char data[MAXSIZE];
  int top;
}seqstack;

seqstack *init_seqstack(){
   seqstack *s;
   s=malloc(sizeof(seqstack));
   s->top=-1;
   return s;
}

void inputstack(seqstack *s,char x){
    if(s->top==MAXSIZE-1)
    {  printf("The stack is full!");
       return;
    }
    else
    {  s->top++;
       s->data[s->top]=x;
    }
}

int outputstack(seqstack *s){
   int n;
   n=s->top;
   for(;s->top>=n/2;s->top--){
       if( s->data[s->top]!=s->data[n-s->top]) break;
   }
     if(s->top>=n/2)
      return 0;
         else
            return 1;
}

void main()
{  int flag=1,n=0;
   char x;
   seqstack *s;
   s=init_seqstack();   while(flag)
   {
     scanf("%c",&x);
     if(x=='#')
     { flag=0;       if(outputstack(s))
         printf("yes!");
           else
             printf("no!");
     }
     if(x!='\n'){
     inputstack(s,x);}
   }   getch();
 }
