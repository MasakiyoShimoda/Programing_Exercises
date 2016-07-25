//
//  main.c
//  2-5
//
//  Created by 下田将斉 on 2016/07/23.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define QUESTION 5

void count();
double microtime();
void question(int);

int main(int argc, const char * argv[]) {
    int digit = -2;
    double start, end;
    
    while(digit <= 0 || digit > 4){
        printf("計算の桁数を指定してください(5桁以上不可)：");
        scanf("%d", &digit);
    }
    count();
    start = microtime();
    question(digit);
    end = microtime();
    
    printf("Done!\nかかった時間:%lf秒\n", end - start);
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

void question(int digit){
    int frontNum[QUESTION] = {}, rearNum[QUESTION] = {}, answerNum[QUESTION] = {}, randNum[] = {9, 90, 900, 9000}, limitNum[] = {1, 10, 100, 1000};
    int i, k;
    /*問題の数字指定*/
    srand((unsigned int)time(NULL));
    for(i = 0; i < QUESTION; i++ ){
        frontNum[i] = rand() % randNum[digit-1] + limitNum[digit-1];
        rearNum[i] = rand() % randNum[digit-1] + limitNum[digit-1];
    }
    /*問題表示と確認*/
    k = rand()%QUESTION + 1;
    for (i = 0; i < QUESTION; i++) {
        if (i == k) {
            while (frontNum[i] - rearNum[i] != answerNum[i]) {
                printf("[Q%d] %d - %d :", i+1, frontNum[i], rearNum[i]);
                scanf("%d", &answerNum[i]);
                if (frontNum[i] - rearNum[i] != answerNum[i])
                    puts("Wrong answer");
                
            }
        }else{
            while (frontNum[i] + rearNum[i] != answerNum[i]) {
                printf("[Q%d] %d + %d :", i+1, frontNum[i], rearNum[i]);
                scanf("%d", &answerNum[i]);
                if (frontNum[i] + rearNum[i] != answerNum[i])
                    puts("Wrong answer");
                
            }
        }
    }
}
