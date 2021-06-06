//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdio.h"
#include "stdlib.h"

void main(){
    FILE *fp;
    char ch;
    char file[255];
    printf("file name \n");
//    scanf("%s", file);
    if ((fp=fopen("aa.txt", "at+")) == NULL){
        printf("file error.\n");
        exit(0);
    }
    printf("Input a string(ENTER for end input)\n");
    while ((ch=getchar()) != '\n'){
        fputc(ch, fp);
    }
    fclose(fp);
}

