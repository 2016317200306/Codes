#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[8];
    char sex[2];
    int age;
    long telephone;
    char address[20];
}person;

void GetData(person *student) {//形参为结构体指针
    printf("请输入姓名、性别、年龄、电话号码、籍贯：\n");
    scanf("%s",student->name);
    scanf("%s",student->sex);
    scanf("%d",student->age);
    scanf("%ld",student->telephone);
    scanf("%s",student->address);
}

void Get_Data(person &student) {//形参为结构引用类型
    printf("请输入姓名、性别、年龄、电话号码、籍贯：\n");
    scanf("%s",student.name);
    scanf("%s",student.sex);
    scanf("%d",student.age);
    scanf("%ld",student.telephone);
    scanf("%s",student.address);
}

void OutData(person student) {
    printf("name:%s\n",student.name);
    printf("sex:%s\n",student.sex);
    printf("age:%d\n",student.age);
    printf("telephone:%d\n",student.telephone);
    printf("address:%s\n",student.address);
}

int main() {
    person student;//person *student;
    //student = (person *)malloc(sizeof(person));
    //GetData(student);
    Get_Data(student);
    OutData(student);//OutData(*student);
}
