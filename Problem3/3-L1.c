//
//  main.c
//  random
//
//  Created by 下田将斉 on 2016/10/16.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void show(int *data, int xlen);
void swap(int *data, int len, int x, int y);
void shuffle(int *data, int xlen);

int main(int argc, const char * argv[]) {
    // insert code here...
    int x[] = {1,2,3,4,5};
    int xlen = sizeof(x) / sizeof(x[0]);
    srandom((unsigned int)time(NULL));
    
    puts("初期状態");
    show(x, xlen);
    
    shuffle(x, xlen);
    
    puts("シャッフルします");
    show(x, xlen);
    
    return 0;
}

void show(int *data, int len){
    int i;
    
    for(i = 0; i < len; i ++){
        printf("%d", data[i]);
        
        if(i != len-1)
            putchar(' ');
    }
    putchar('\n');
}

void swap(int *data, int len, int x, int y){
    if(x < 0 || y < 0 || x > len-1 || y > len-1){
        puts("範囲外の要素を参照しようとしました.交換できません.");
        return;
    }
    
    int buff;
    buff = data[x];
    data[x] = data[y];
    data[y] = buff;
}

void shuffle(int *data, int len){
    int i, j, flag = 0;
    char str1[100] = {}, str2[100] = {};
    
    for (i = 0; i < len; i++)
        sprintf(str1, "%s%d", str1, data[i]);
    while(flag == 0){
        for(i = 0; i < len; i ++){
            do{
                j = rand()%len;
            }while(i == j);
            swap(data, len, i, j);
        }
        for (i = 0; i < len; i++)
            sprintf(str2, "%s%d", str2, data[i]);
        if (strcmp(str1, str2) != 0)
            flag = 1;
        else
            memset(str2, '\0', 100);
    }
}
