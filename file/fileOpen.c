//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdio.h"
#include "stdlib.h"
void main(){
    FILE *fp;
    char filePath[255];
    scanf("%s", filePath);
    if ((fp=fopen(filePath, "r")) == NULL){
        printf("Cannot open this file. \n");
        exit(0);
    }else{
        printf("open file %s", filePath);
        fclose(fp);
    }
}

