//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdio.h"

void main(){
    char fileName[255];
    char newFileName[255];
    printf("file name!\n");
    scanf("%s", fileName);
    printf("new file name!\n");
    scanf("%s", newFileName);
    if (rename(fileName, newFileName) == 0){
        printf("rename success!\n");
    } else{
        printf("rename failure!\n");
    }
}
