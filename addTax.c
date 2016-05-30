//
//  main.c
//  addTax
//
//  Created by 下田将斉 on 2016/05/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

#define TAX 1.08;
#define PRODUCT_NUMVER 3;

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, total = 0, productNum = PRODUCT_NUMVER;
    double tax = TAX;
    int productValue[20] = {0};
    for (i = 0; i < productNum; i++) {
        printf("商品%d:", i+1);
        scanf("%d", &productValue[i]);
        for (; productValue[i] > 100000 || productValue[i] < 0; ) {
            printf("正しい価格を入力してください\n");
            printf("商品%d:", i+1);
            scanf("%d", &productValue[i]);
        }
        total += productValue[i];
    }
    printf("計（税別）:%d\n", total);
    printf("税率: %.lf％\n", tax * 100 - 100);
    printf("計（税込）:%.lf\n", (double)total * tax);
    
    return 0;
}

