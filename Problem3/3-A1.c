//
//  main.c
//  3-A1
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

#define QUESTION 3 /*出題回数*/

void count();
double microtime();
void question(int *data, int xlen);
void swap(int *data, int len, int x, int y);
void shuffle(int *data, int xlen);
void show(int *data, int xlen, int que);

int main(int argc, const char * argv[]) {
    int x[] = {1,2,3,4,5, 6, 7, 8, 9};
    int xlen = sizeof(x) / sizeof(x[0]);
    double start, end;
    srandom((unsigned int)time(NULL));
    
    puts("Find the missing number!");
    count();
    start = microtime();
    question(x, xlen);
    end = microtime();
    
    printf("Done!\nTime:%.2lf[s]\n", end - start);
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

void question(int *data, int len){
    int i, que, number = -1;
    for (i = 0; i < QUESTION; i++) {
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
    }
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
        j = rand()%len;
        swap(data, len, i, j);
    }
}
