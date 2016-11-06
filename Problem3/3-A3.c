//
//  main.c
//  3-A3
//
//  Created by 下田将斉 on 2016/10/25.
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
void show(int *data, int xlen);
int serchAnswer(int *data, int len);

int main(int argc, const char * argv[]) {
    int x[] = {1,2,3,4,5, 6, 7, 8, 9};
    int right, xlen = sizeof(x) / sizeof(x[0]);
    srand((unsigned int)time(NULL));
    
    
    
    puts("-------------------ルール説明--------------------");
    puts("3x3のランダムの数字が表示されます。");
    puts("5 3 2   この場合は");
    puts("4 8 7　　5,8,9をすべてかけた数、360が答えになります。");
    puts("6 1 9　　縦横斜めの３つの数字を掛けて一番大きな数字が答えとなります。");
    puts("-----------------------------------------------");
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
    int i, que, number = -1, problem;
    
    printf("問題数を選択してください\n>>");
    scanf("%d", &problem);
    count();
    for (i = 0; problem > i; i++) {
        printf("[Q%d]", i+1);
        shuffle(data, len);
        show(data, len);
        que = serchAnswer(data, len);
        printf("\n>>");
        scanf("%d", &number);
        while (number != que) {
            printf("Wrong! Try again : ");
            scanf("%d", &number);
        }
        puts("Correct!");
        end = microtime();
        printf(">> TIME : %.2lf[s]\n", end - start);
    }
    return i;
    
}

void show(int *data, int len){
    int i;
    for(i = 0; i < len; i ++){
        if (i % 3 == 0)
            printf("\n");
        printf("%d", data[i]);
        if(i != len-1)
            putchar(' ');
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
    
    for(i = (len-1); 0 < i; i --){
        j = rand()%(i+1);
        swap(data, len, i, j);
    }
}

int serchAnswer(int *data, int len){
    int answer = 0, buff, i, x = 0, y = 0, z = 0;
    for (i = 0; i < 8; i++) {
        if (i == 0){
            x = 0; y = 1; z = 2;}
        if (i == 1){
            x = 3;y = 4;z = 5;}
        if (i == 2){
            x = 6;y = 7;z = 8;}
        if (i == 3){
            x = 0;y = 3;z = 6;}
        if (i == 4){
            x = 1;y = 4;z = 7;}
        if (i == 5){
            x = 2;y = 5;z = 8;}
        if (i == 6){
            x = 0;y = 4;z = 8;}
        if (i == 7){
            x = 2;y = 4;z = 6;}
        buff = data[x] * data[y] * data[z];
        //printf("\ndata=%d, %d, %d\nbuff = %d", data[x], data[y], data[z], buff);
        if (answer <= buff)
            answer = buff;
    }
    return answer;
}
