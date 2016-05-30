//
//  main.c
//  addTax
//
//  Created by 下田将斉 on 2016/05/24.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

double setProduct(productNumber){
    int i, productValue[20] = {0};
    double total;
    for (i = 0; i < productNumber; i++) {
        printf("商品%d:", i + 1);
        scanf("%d", &productValue[i]);
        total += productValue[i];
    }
    printf("計(税別):%lf", total);
    return total;
}


int addTax(tax, totalProductValue){
    tax = tax * 0.01 + 1.0;
    totalProductValue *= tax;
    printf("計(税別):%d", totalProductValue);
    return totalProductValue;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int productNumber = 3;
    double total;
    double tax = 8.0;
    total = setProduct(productNumber);
    addTax(tax, total);
    
    return 0;
}


