//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdlib.h"
#include "stdio.h"
typedef struct student{
    int num;
    char name[20];
    int age;
}student;

void dataStructRead();

void dataStructWrite();

void openError();

void dataStructRewind();

void openFile(const char *model);

void dataStructFseek();

void dataStructFtell();

const char file[255] = "student.txt";

struct student stu;

FILE *fp;

void main(){
    dataStructWrite();
    dataStructRead();
    dataStructRewind();
    dataStructFseek();
    dataStructFtell();
}

void dataStructFtell(){
    fseek(fp, 0L, SEEK_END);
    // 文件长度
    int length = ftell(fp);
    printf("file length = %d.\n", length);
    fclose(fp);
}

void dataStructFseek(){
    openFile("ab+");
    fseek(fp, sizeof(stu), 0);
    fread(&stu, sizeof(stu), 1, fp);
    printf("num=%d name=%s age=%d.\n", stu.num, stu.name, stu.age);
    fclose(fp);
}

void dataStructRewind(){
    student stus[3];
    openFile("ab+");
    for (int j = 0; j < 3; ++j) {
        scanf("%d%s%d", &stus[j].num, &stus[j].name, &stus[j].age);
    }
    fwrite(&stus, sizeof(stus), 3, fp);
    rewind(fp);
    // 从文件首将文件内容保存在 stu
    fread(&stus, sizeof(stus), 3, fp);
    for (int j = 0; j < 3; ++j) {
        printf("num=%d name=%s age=%d\n", stus[j].num, stus[j].name, stus[j].age);
    }
    fclose(fp);
}


void dataStructWrite(){
    scanf("%d%s%d", &stu.num, &stu.name, &stu.age);
    openFile("wb");
    // 将内容保存在结构体重
    fwrite(&stu, sizeof(stu), 1, fp);
    fclose(fp);
}

void dataStructRead(){
    openFile("rb");
    fread(&stu, sizeof(stu), 1, fp);
    printf("num=%d name=%s age=%d\n", stu.num, stu.name, stu.age);
    fclose(fp);
}

void openFile(const char *model){
    if (!(fp=fopen(file, model))){
        openError();
    }
}

void openError(){
    printf("open error");
    exit(0);
}