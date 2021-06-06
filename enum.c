//
// Created by 朝花夕誓 on 2021/6/6.
//

#include "stdlib.h"
#include "stdio.h"

enum colors{
    red,
    blue,
    green,
    black,
    white,
    yellow
};

int main(){
    system("chcp 65001");
    enum colors col[6];
    printf("colors size is -> %d\n", sizeof(col));
    int n,j;
    printf("0:red, 1:blue, 2:green, 3:black, 4:white, 5:yellow\n");
    printf("请输入6个颜色数目:\n");
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &n);
        if (n < 0 || n > 5){
            printf("输入颜色值错误，请重新输入！");
            exit(0);    // 关闭所有文件，终止正在执行的程序
        }else{
            switch (n) {
                case 0: col[i] = red;   break;
                case 1: col[i] = blue;   break;
                case 2: col[i] = green;   break;
                case 3: col[i] = black;   break;
                case 4: col[i] = white;   break;
                case 5: col[i] = yellow;   break;
            }
        }
    }
    for (int i = 0; i < 6; ++i) {
        switch (col[i]) {
            case red:printf("red");     break;
            case blue:printf("blue");   break;
            case green:printf("green");     break;
            case black:printf("black");     break;
            case white:printf("white");     break;
            case yellow:printf("yellow");     break;
            printf("\t");
        }
        printf("\n");
    }
};

