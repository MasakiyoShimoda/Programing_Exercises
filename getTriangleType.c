//
//  main.c
//  getTriangelTipe
//
//  Created by 下田将斉 on 2016/06/27.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

#define TRIANGLE_EQ   1    /* 正三角形 */
#define TRIANGLE_ISO  2    /* 二等辺三角形 */
#define TRIANGLE_SCL  3    /* 不等辺三角形 */
#define TRIANGLE_NA   -1   /* 三角形でない(または不正な入力値) */
#define MAX_LENGTH 10000   /* 三角形の一辺の最大値 */

int gettriangletype(int a, int b, int c) {
    /* 実装せよ */
    
    //範囲内の数字のみ処理を行う.
    if(0 < a && a <= MAX_LENGTH && 0 < b && b <= MAX_LENGTH && 0 < c && c <= MAX_LENGTH){
        if(a+b <= c || a+c <= b || b+c <= a)
            return TRIANGLE_NA;
        if(a == b && b == c)
            return TRIANGLE_EQ;
        if(a == b || a == c || b == c)
            return TRIANGLE_ISO;
        if(a < b+c || b < a+c || c < a+b)
            return TRIANGLE_SCL;
    }
    return TRIANGLE_NA;
}

void test_eq(void) {
    /* 正三角形との判定を期待するテストケース群 */
    assert(gettriangletype(50, 50, 50) == TRIANGLE_EQ);
    assert(gettriangletype(MAX_LENGTH, MAX_LENGTH, MAX_LENGTH) == TRIANGLE_EQ);
}

void test_iso(void) {
    /* 二等辺三角形との判定を期待するテストケース群 */
    assert(gettriangletype(3, 4, 3) == TRIANGLE_ISO);
    assert(gettriangletype(4, 3, 3) == TRIANGLE_ISO);
    assert(gettriangletype(3, 3, 4) == TRIANGLE_ISO);
}

void test_scl(void) {
    /* 不等辺三角形との判定を期待するテストケース群 */
    assert(gettriangletype(3, 4, 5) == TRIANGLE_SCL);
}

void test_na(void) {
    /* 三角形にならないとの判定を期待するテストケース群 */
    assert(gettriangletype(2, 2, 4) == TRIANGLE_NA);
    assert(gettriangletype(2, 4, 2) == TRIANGLE_NA);
    assert(gettriangletype(4, 2, 2) == TRIANGLE_NA);
    assert(gettriangletype(1, 2, 4) == TRIANGLE_NA);
    assert(gettriangletype(2, 4, 1) == TRIANGLE_NA);
    assert(gettriangletype(4, 1, 2) == TRIANGLE_NA);
}

void test_invalid(void) {
    /* 不正な入力値との判定を期待するテストケース群 */
    assert(gettriangletype(MAX_LENGTH, MAX_LENGTH, MAX_LENGTH+1) == TRIANGLE_NA);
    assert(gettriangletype(0, 4, 5) == TRIANGLE_NA);
    assert(gettriangletype(3, -1, 5) == TRIANGLE_NA);
    assert(gettriangletype(0, 0, 0) == TRIANGLE_NA);
}

void dotest(void) {
    test_eq();
    puts("Passed: test_eq");
    test_iso();
    puts("Passed: test_iso");
    test_scl();
    puts("Passed: test_scl");
    test_na();
    puts("Passed: test_na");
    test_invalid();
    puts("Passed: test_invalid");
    puts("All passed!");
}

int main(int argc, char *argv[]) {
    dotest();
    return 0;
}
