//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdlib.h"
#include "stdio.h"
struct {
    long num;
    char name[10];
    char sex;
    char job;
    union {
        int classNum;
        char office[10];
    } category;
}person[2];

void main(){
    int i;
    char numStr[20];
    for (int j = 0; j < 2; j++) {
        printf("请输入编号: ");
        gets(numStr);
        person[i].num = atoi(numStr);   //atoi函数将参数字符串转换成长整型数
        printf("请输入姓名: ");
        scanf("%s", person[i].name);
        getchar();  // 用来接收输入姓名后的"回车符"，下同
        printf("请输入性别(M/F): ");
        scanf("%c", &person[i].sex);
        getchar();
        printf("请输入职业(t/s): ");
        person[i].job = getchar();
        if (person[i].job == 's'){
            printf("请输入班级号: ");
            scanf("%d", &person[i].category.classNum);
            getchar();
        }else{
            if (person[i].job == 't'){
                printf("请输入职称: ");
                scanf("%s", person[i].category.office);
                getchar();
            }else{
                printf("input error!");
            }
        }
    }
    printf("\n\n");
    printf(" No.    Name    Sex     Job     class/office\n");
    for (int j = 0; j < 2; j++) {
        printf("%-10d%-11s%", person[i].num, person[i].name);
        if (person[i].sex == 'M' || person[i].sex =='m') printf("男");
        if (person[i].sex == 'F' || person[i].sex == 'f') printf("女");
        if (person[i].job == 's') printf("\t\t学生");
        if (person[i].job == 't') printf("\t\t教师");
        if (person[i].job == 's') printf("\t\t%d\n", person[i].category.classNum);
        if (person[i].job == 't') printf("\t\t%d\n", person[i].category.office);
    }
}

