//
//  main.c
//  3-A4
//
//  Created by 下田将斉 on 2016/11/21.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

#define PATH "/home/lecture/hi-3proen/ejwords.dat"
#define PATH_MAC "/Users/MasakiyoS/Desktop/ProgramingExercise/3/3-A4/ejwords.txt"
#define WORDLEN 50

void shuffle(int *, int);
void swap(int *, int, int, int);
int reSerect(int, int);
double microtime();

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fp;
    int count = 0, i, j, max, select, answer, flag = 0, miss = 0;
    int *data, *data2;
    double start , end;
    char **jp_word, **en_word;
    char c, w_en[50], w_jp[50];
    srand((unsigned int)time(NULL));
    
    /*ファイルを開く*/
    if((fp = fopen(PATH_MAC, "r")) == NULL){
        printf("ファイルが開けませんでした\n");
        exit(9);
    }
    
    /*行数をカウント*/
    while((c = fgetc(fp)) != EOF)
        if(c == '\n')
            count ++;
    fseek(fp, 0L, SEEK_SET);
    
    /*Wordのメモリ確保*/
    en_word = (char**)malloc(sizeof(char*) * count);
    jp_word = (char**)malloc(sizeof(char*) * count);
    data = (int*)malloc(sizeof(int) * count);
    for (i=0;i<count;i++){
        jp_word[i] = (char*)malloc(sizeof(char) * WORDLEN);
        en_word[i] = (char*)malloc(sizeof(char) * WORDLEN);
        data[i] = i;
    }
    
    shuffle(data, count);
    /*ファイルを配列に取り込む*/
    i = 0;
    while(fscanf(fp, "%s%s", w_en, w_jp) != EOF){
        strcpy(en_word[i], w_en);
        strcpy(jp_word[i], w_jp);
        i ++;
    }
    
    /*問題*/
    puts("-------------User Setting-------------");
    puts("問題数を選択してください(最大100問)");
    max = reSelect(1, 100);
    puts("選択肢の数を選択してください(最大8個)");
    select = reSelect(2, 8);
    data2 = (int*)malloc(sizeof(int) * select);
    for (i = 0; i < select; i++)
        data2[i] = i;
    
    puts("---------------Question---------------");
    start = microtime();
    for (i = 1; i <= max; i++) {
        shuffle(data2, select);
        printf("[Q%d]:【 %s 】\n", i, jp_word[data[i]]);
        
        /*選択肢表示*/
        for (j = 0; j < select; j++) {
            if (data[i] > max - select)
                printf("\t%d.%s\n", j + 1, en_word[data[i] + data2[j]]);
            else
                printf("\t%d.%s\n", j + 1, en_word[data[i] + data2[j]]);
            if (data2[j] == 0)
                flag = j+1;
        }
        
        /*解答枠*/
        do{
            answer = reSelect(1, select);
            if (answer == flag) {
                puts("Current!");
                end = microtime();
                printf("Time:%.2f\n", end - start);
            }else{
                puts("Missing!");
                miss++;
            }
        }while (answer != flag);
    }
    
    end = microtime();
    printf("Total Time:%.2f\n", end - start);
    printf("Missing:%d\n", miss);
    
    /*mallocで確保したメモリを開放し、ファイルを閉じる*/
    for (i = 0; i < count; i++) {
        free(en_word[i]);
        free(jp_word[i]);
    }
    free(en_word);
    free(jp_word);
    fclose(fp);
    
    return 0;
}

void shuffle(int *data, int len){
    int i, j;
    
    for(i = (len-1); 0 < i; i --){
        j = rand()%(i+1);
        swap(data, len, i, j);
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

int reSelect(int min, int max){
    int selectNumber;
    printf(">>");
    scanf("%d", &selectNumber);
    while(min > selectNumber || selectNumber > max){
        puts("もう1度選択してください");
        printf(">>");
        scanf("%d", &selectNumber);
    }
    return selectNumber;
}

double microtime(){
    struct timeval tv;
    int ret;
    ret = gettimeofday(&tv, NULL);
    if(ret == 0){
        return tv.tv_sec + (double)tv.tv_usec/1000000;
    }else{
        return -1;
    }
}

