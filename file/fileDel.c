//
// Created by 朝花夕誓 on 2021/6/6.
//
#include "stdio.h"

void main(){
    printf("remove file:");
    char file[255];
    scanf("%s", file);
    if(remove(file)==0){
        printf("remove success!");
    } else{
        printf("remove failure!");
    }
}

