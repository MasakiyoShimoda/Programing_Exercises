//
//  main.c
//  CarryACheese
//
//  Created by 下田将斉 on 2016/07/16.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 10000

void judgeEnter(int enter, int sizeOfEnter[], int size1, int size2, int size3);

int main(int argc, const char * argv[]) {
    // insert code here...
    int enter, i;
    double size1, size2, size3, depth, width, height;
    int *sizeOfEnter;
    
    scanf("%lf %lf %lf", &depth, &width, &height); /*縦横高さ*/
    scanf("%d", &enter);                        /*入口の数*/
    /*エラー出力*/
    if (enter > LIMIT) {
        printf("ERROR(orver %d)\n", LIMIT);
        return 0;
    }else if (enter < 1){
        printf("ERORR(under 1)\n");
        return 0;
    }
    
    /*チーズの３つの外接円の半径を求める*/
    size1 = sqrt((depth*depth) + (height*height) * 0.5);
    size2 = sqrt((depth*depth) + (width*width)) * 0.5;
    size3 = sqrt((height*height) + (width*width)) * 0.5;
    
    /*入口のサイズ*/
    sizeOfEnter = (int *)malloc(sizeof(int) * enter + 3);
    if (sizeOfEnter == NULL)
        exit(0);
    for (i = 0; i < enter + 3; i++) {
        scanf("%d", &sizeOfEnter[i]);
        
        /*入力終了*/
        if (sizeOfEnter[i] == 0 && sizeOfEnter[i-1] == 0 && sizeOfEnter[i-2] == 0){
            judgeEnter(enter, sizeOfEnter, size1, size2, size3);
            return 0;
        }
        /*入口のサイズのエラー出力*/
        if (sizeOfEnter[i] < 0){
            printf("ERORR(under 0)\n");
            return 0;
        }
    }
    
    judgeEnter(enter, sizeOfEnter, size1, size2, size3);
    
    free(sizeOfEnter);
    
    return 0;
}
/*入れるか入れないか判定*/
void judgeEnter(int enter, int sizeOfEnter[], int size1, int size2, int size3){
    int i;
    for (i = 0; i < enter; i++) {
        if (sizeOfEnter[i] > size1 || sizeOfEnter[i] > size2 || sizeOfEnter[i] > size3)
            printf("OK\n");
        else
            printf("NA\n");
    }
    
}
