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

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE *fp;
    int count, i, j;
    char **jp_word, **en_word;
    char c, ch[50];
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
    
    /*Wordのメモリ確保*/
    en_word = (char**)malloc(sizeof(char*) * count);
    jp_word = (char**)malloc(sizeof(char*) * count);
    for (i=0;i<count;i++){
        jp_word[i] = (char*)malloc(sizeof(char) * WORDLEN);
        en_word[i] = (char*)malloc(sizeof(char) * WORDLEN);
    }
    
    //strcpy(en_word[3], "aaaaaa");
    //strcpy(jp_word[3], "bbbbb");
    
    for (i = 0; i < count; i++){
        fgets(ch, WORDLEN, fp);
        //printf("%s", ch);
        //fscanf(fp, "%s%s", en_word[i], jp_word[i]);
    }
    
    //for (i = 0; i < count; i++) {
        printf("%s", en_word[2]);
        printf("%s", jp_word[2]);
    //}
    
    printf("データの数:%d\n", count);
    for (i = 0; i < count; i++) {
        free(en_word[i]);
        free(jp_word[i]);
    }
    free(en_word);
    free(jp_word);
    fclose(fp);
    
    return 0;
}
/*
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
 */
