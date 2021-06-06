#include <stdio.h>
#include "stdlib.h"
struct student{
    int num;
    char name[20];
    char sex[3];
    int age;
};

int main() {
    // 控制台输出格式转换utf-8 65001
    system("chcp 65001");
    struct student stu[3] = {{1,"Jack", "男", 17},
                             {2, "Joy", "男", 18},
                             {3, "Lucy", "女", 16}};
    struct student *pStu;
    for(pStu = stu; pStu < stu+3; pStu++){
        printf("num = %d  name = %s  sex = %s  age = %d \n", pStu->num, pStu->name, pStu->sex, pStu->age);
    }
    return 0;
}
