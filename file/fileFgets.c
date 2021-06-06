//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdlib.h"
#include "stdio.h"
// 读取文件
void main(){
    FILE *fp;
    char ch[20];
    if ((fp=fopen("text.txt", "at+")) == NULL){
        printf("file error.");
        exit(0);
    }
    printf("Output a string.\n");
    while ((fgets(ch, 10, fp)) != NULL){
        printf("%s", ch);
    }
    printf("\n");
    fclose(fp);
}
