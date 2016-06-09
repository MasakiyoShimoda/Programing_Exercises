//
//  main.c
//  PWCheck
//
//  Created by 下田将斉 on 2016/06/06.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define UNDER_CHAR 4
#define OVER_CHAR 8
#define PASS argv[1]

int main(int argc, const char * argv[]) {
    // insert code here...
    //ERROR判定
    int i = 0, j, alpha = 0, symbol = 0, digit = 0, other = 0;
    
    if (argc == 1){
        printf("ERROR\n");
        return 0;
    }else if (argc > 2){
        printf("ERROR\n");
        return 0;
    }
    
    //4文字以下8文字以内判定
    while(PASS[i] != '\0')
        i++;
    
    if (i < UNDER_CHAR){
        printf("FALSE\n");
        return 0;
    }else if(i > OVER_CHAR){
        printf("FALSE\n");
        return 0;
    }
    
    //大文字小文字記号判定
    while (i != j) {
        if (isalpha(PASS[j]))
            alpha++;
        else if(isdigit(PASS[j]))
            digit++;
        else if(PASS[j] == '+' || PASS[j] == '-' || PASS[j] == '_')
            symbol++;
        else
            other++;
        j++;
    }
    if (alpha == 0 || digit == 0 || symbol || 0 && other != 0) {
        printf("FALSE\n");
        return 0;
    } else {
        printf("TRUE\n");
        return 0;
    }
}
