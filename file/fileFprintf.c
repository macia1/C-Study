//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdlib.h"
#include "stdio.h"
// 文件写出
typedef struct student{
    int num;
    char name[20];
    int age;
}student;

void main(){
    FILE *fp;
    struct student stu;         // 定义学生结构体变量并赋值
    scanf("%d%s%d", &stu.num, &stu.name, &stu.age);
    // open file
    if ((fp=fopen("student.txt", "ab+")) == NULL){
        printf("cannot open file.\n");
        exit(0);
    }
    // 将学生信息写入 text.txt
    fprintf(fp, "%d %s %d", stu.num, stu.name, stu.age);
    // 关闭文件
    fclose(fp);
}
