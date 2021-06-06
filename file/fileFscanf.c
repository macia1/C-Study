//
// Created by 朝花夕誓 on 2021/6/6.
// 文件读取
#include "stdio.h"
#include "stdlib.h"
typedef struct student{
    int num;
    char name[20];
    int age;
}student;

void main(){
    FILE *fp;
    student stu;
    if ((fp=fopen("student.txt", "ab+")) == NULL){
        printf("cannot open file.\n");
        exit(0);
    }
    fscanf(fp, "%d %s %d",&stu.num, &stu.name, &stu.age);
    // 将student.txt学生信息读取到内存中
    printf("num=%d name=%s age=%d\n", stu.num, stu.name, stu.age);
    fclose(fp);
}

