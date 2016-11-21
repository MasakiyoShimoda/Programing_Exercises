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

#define PATH /home/lecture/hi-3proen/ejwords.dat
#define PATH_MAC /Users/MasakiyoS/Desktop/ProgramingExercise/3/3-A4/ejwords.dat
#define WORDLEN 20

void shuffle(int *, int);
void swap(int *, int, int, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fp;
    int *data, i = 0;
    char word[20], **jp_word, **en_word;
    srand((unsigned int)time(NULL));
    
    if((fp = fopen("PATH_MAC", "r")) == NULL){
        printf("ファイルが開けませんでした");
        fclose(fp);
        exit(9);
    }
    
    while(fscanf(fp, "%s", word))
        i++;
    
    /*Wordのメモリ確保*/
    en_word[20] = (char *)malloc(sizeof(char) * (i/2));
    en_word[20] = (char *)malloc(sizeof(char) * (i/2));
    
    printf("データの数:%d", i/2);
    
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


