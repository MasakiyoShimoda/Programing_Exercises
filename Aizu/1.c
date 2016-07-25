//
//  main.c
//  Aizu-1
//
//  Created by 下田将斉 on 2016/07/16.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define DEPTH 10
#define LIMIT 100

void printTable(int i, int table[DEPTH][WIDTH + 1][HEIGHT + 1]);

int main(int argc, const char * argv[]) {
    // insert code here...
    int table[DEPTH][WIDTH + 1][HEIGHT + 1] = {};
    int i, j, k, n = 1;
    
    for (i = 0; n != 0; i++) {
        /*縦横制限*/
        scanf("%d", &n);
        if (n == 0) {
            printTable(i, table);
            return 0;
        }else if (n > WIDTH) {
            printf("ERORR(over %d)\n", WIDTH);
            return 0;
        }else if(n < 1){
            printf("ERORR(under 1)");
            return 0;
        }
        
        /*表入力*/
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++){
                scanf("%d", &table[i][j][k]);
                if (table[i][j][k] > LIMIT) {
                    printf("ERORR(over %d)", LIMIT);
                    return 0;
                }
            }
        }
    }
    
    return 0;
}

void printTable(int i, int table[DEPTH][WIDTH + 1][HEIGHT + 1]){
    int j, k = 0, l;
    /*合計計算*/
    for(l = 0; l < i; l++){
        for (j = 0; j <= k; j++) {
            for (k = 0; table[l][j][k] != 0; k++){
                /*横合計*/
                table[l][j][HEIGHT] += table[l][j][k];
                /*縦合計*/
                table[l][WIDTH][k] += table[l][j][k];
                /*すべての合計*/
                table[l][WIDTH][HEIGHT] += table[l][j][k];
            }
        }
    }
    /*表出力*/
    k = 1;
    for(l = 0; l < i; l++){
        for (j = 0; j < k; j++) {
            for (k = 0; table[l][j][k] != 0; k++)
                printf("%5d", table[l][j][k]);
            printf("%5d\n", table[l][j][HEIGHT]);
        }
        for(k = 0; k < j; k++)
            printf("%5d", table[l][WIDTH][k]);
        printf("%5d", table[l][WIDTH][HEIGHT]);
        printf("\n");
    }
}
