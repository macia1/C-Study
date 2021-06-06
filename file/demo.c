//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct{
    int num;
    char name[20];
    date birthday;
}student;

FILE *fp;
FILE  *fpNew;
student stu;
student *pstu = &stu;

char file[255] = "sturecord.txt";

void openError(){
    printf("open error");
    exit(0);
}

void openFile(const char *model){
    if (!(fp=fopen(file, model))){
        openError();
    }
}



void MainShow(){
    printf("\t\t ***学生信息系统***\n");
    printf("\t\t ***1.输入学生记录***\n");
    printf("\t\t ***2.浏览全部学生记录***\n");
    printf("\t\t ***3.按学号查找学生记录***\n");
    printf("\t\t ***4.按学号删除学生记录***\n");
    printf("\t\t ***5.按学号修改学生的姓名***\n");
    printf("\t\t ***6.退出系统***\n");
}

// 1.输入学生记录功能
void InputStudent(){
    char choice;
    printf("请输入学生记录功能\n");
    openFile("at+");
    printf("请输入学生的学号:");
    scanf("%d", &pstu->num);
    printf("请输入学生的姓名:");
    scanf("%s", &pstu->name);
    printf("请输入学生的出生年月日:");
    scanf("%d%d%d", &pstu->birthday.year, &pstu->birthday.month, &pstu->birthday.day);
    printf("num=%-3d", pstu->num);
    printf("num=%-10s", pstu->name);
    printf("birthday=%4d-%2d-%2d\n", pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);

    // 记录信息
    fprintf(fp, "%d %s %d %d %d\n", pstu->num, pstu->name, pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
    fclose(fp);
    printf("是否继续输入学生信息 y or n ?");
    // 清空输入输出缓冲区避免上次输入的换行影响这次输入
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'y'){
        InputStudent();
    }
}

//2. 浏览全部学生记录
void OutPutStudent(){
    printf("输出学生信息\n");
    openFile("at+");
    while (!feof(fp)){
        fscanf(fp, "%d%s%d%d%d\n", &pstu->num, &pstu->name, &pstu->birthday.year, &pstu->birthday.month, &pstu->birthday.day);
        printf("学生的学号为 %d\n", pstu->num);
        printf("学生的姓名为 %s\n", pstu->name);
        printf("学生的出生年-月-日 = %d\n", pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
    }
    fclose(fp);
}

//3. 按学号查找学生记录
void FindByNum(){
    int num;
    int find = 0;
    printf("按学号查找学生记录\n");
    openFile("at+");
    printf("请输入要查找的学生的学号:");
    scanf("%d", &num);
    while (!feof(fp)){
        fscanf(fp, "%d%s%d%d%d\n", &pstu->num, pstu->name, &pstu->birthday.year, &pstu->birthday.month, &pstu->birthday.day);
        if (num==pstu->num){
            printf("学生的学号为%d\n", pstu->num);
            printf("学生的姓名为%d\n", pstu->name);
            printf("学生的出生年-月-日 = %d\n", pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
            printf("\n");
            find = 1;
        }
    }
    if (!find){
        printf("查无此人!\n");
    }
    fclose(fp);
}

//4. 按学号删除学生记录
void DeleteByNum(){
    int num;
    int findDelete = 0;
    printf("按学生删除学生记录\n");
    openFile("at+");
    printf("请输入要删除的学生的学号:");
    scanf("%d", &num);
    while (!feof(fp)){
        fscanf(fp, "%d%s%d%d%d\n", &pstu->num, pstu->name, &pstu->birthday.year, &pstu->birthday.month, &pstu->birthday.day);
        if (num!=pstu->num){
            fprintf(fpNew, "%d%s%d%d%d\n", pstu->num, pstu->name, pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
        }else{
            printf("学生的学号为 %d\n", pstu->num);
            printf("学生的姓名为 %s\n", pstu->name);
            printf("删除成功!");
            printf("学生的出生年-月-日 = %d\n", pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
            findDelete = 1;
        }
    }
    if (!findDelete){
        printf("查无此人!");
    }
    fclose(fp);
    fclose(fpNew);
    // 删除文件
    remove("sturecord.txt");
    rename("stucopy.txt", "sturecord.txt");
}

//5.按学号修改学生的姓名
void AlterNameByNum(){
    int num;
    char name[20];
    int find = 0;
    printf("按学号修改学生的姓名\n");
    openFile("at+");
    if (!(fopen("stucopy.txt", "at+"))){
        printf("file error. \n");
        exit(0);
    }
    printf("请输入要修改的学生的学号:");
    scanf("%d", num);
    while (!feof(fp)){
        fscanf(fp, "%d%s%d%d%d\n", &pstu->num, pstu->name, &pstu->birthday.year, &pstu->birthday.month, &pstu->birthday.day);
        if (num!=pstu->num){
            fprintf(fpNew, "%d%s%d%d%d\n", pstu->num, pstu->name, pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
        }else{
            printf("请输入修改后的名字");
            scanf("%s", name);
            strcpy(pstu->name, name);
            fprintf(fpNew, "%d %s %d %d %d\n", pstu->num, pstu->name, pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
            printf("学生的学号为 %d\n", pstu->num);
            printf("学生的姓名为 %s\n", pstu->name);
            printf("删除成功!");
            printf("学生的出生年-月-日 = %d\n", pstu->birthday.year, pstu->birthday.month, pstu->birthday.day);
            printf("修改成功\n");
            find = 1;
        }
    }
    if (!find){
        printf("查无此人\n");
    }
    fclose(fp);
    fclose(fpNew);
    remove("sturecord.txt");
    rename("stucopy.txt", "sturecord.txt");
}

void Select(){
    int num;
    printf("请选择功能\n");
    scanf("%d", &num);
    switch (num) {
        case 1:
            InputStudent();
            MainShow();
            Select();
            break;
        case 2:
            OutPutStudent();
            MainShow();
            Select();
            break;
        case 3:
            FindByNum();
            MainShow();
            Select();
            break;
        case 4:
            DeleteByNum();
            MainShow();
            Select();
            break;
        case 5:
            AlterNameByNum();
            MainShow();
            Select();
            break;
        case 6:
            printf("系统结束, 谢谢再见\n");
            exit(0);
    }
}

void main(){
    MainShow();
    Select();
}