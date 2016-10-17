//
//  main.c
//  3-A2
//
//  Created by 下田将斉 on 2016/10/17.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

#define TIME_LIMIT 10 /*制限時間*/

void count();
double microtime();
int question(int *data, int xlen);
void swap(int *data, int len, int x, int y);
void shuffle(int *data, int xlen);
void show(int *data, int xlen, int que);

int main(int argc, const char * argv[]) {
    int x[] = {1,2,3,4,5, 6, 7, 8, 9};
    int right, xlen = sizeof(x) / sizeof(x[0]);
    srandom((unsigned int)time(NULL));
    
    puts("Find the missing number!");
    count();
    right = question(x, xlen);
    
    printf("Time is up!\nYou've got %d points\n", right);
    return 0;
}
/*カウント関数*/
void count(void){
    puts("3");
    sleep(1);
    puts("2");
    sleep(1);
    puts("1");
    sleep(1);
    puts("start");
}

double microtime(void){
    struct timeval tv;
    int ret;
    ret = gettimeofday(&tv, NULL);
    if(ret == 0){
        return tv.tv_sec + (double)tv.tv_usec/1000000;
    }else{
        return -1;
    }
}

int question(int *data, int len){
    double end = 0, start = microtime();
    int i, que, number = -1;
    for (i = 0; TIME_LIMIT > end - start; i++) {
        que = random()%len;
        printf("[Q%d] ", i+1);
        shuffle(data, len);
        show(data, len, que);
        printf(": ");
        scanf("%d", &number);
        while (number != que) {
            if (number != que)
                printf("Wrong! Try again : ");
            scanf("%d", &number);
        }
        end = microtime();
    }
    return i;
    
}

void show(int *data, int len, int que){
    int i;
    for(i = 0; i < len; i ++){
        if(data[i] != que){
            printf("%d", data[i]);
            if(i != len-1)
                putchar(' ');
        }
    }
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
    int i, j;
    
    for(i = 0; i < len; i ++){
        do{
            j = rand()%len;
        }while(i == j);
        swap(data, len, i, j);
    }
    
}
