//
// Created by 朝花夕誓 on 2021/6/6.
// fgetc 获取字符
// fgets 获取字符串
//
#include "stdlib.h"
#include "stdio.h"

void main(){
    FILE *fp;
    char ch[255];
    if ((fp=fopen("text.txt", "at+")) == NULL){
        printf("file open error.\n");
        exit(0);
    }
    printf("Input a string.\n");
    scanf("%[^\n]", ch);
    fputs(ch, fp);
    fclose(fp);
}

