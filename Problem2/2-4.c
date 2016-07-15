//
//  main.c
//  2-4
//
//  Created by 下田将斉 on 2016/07/15.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>

#define UN_REAL_YEAR 2400
#define LEAP_YEAR 1
#define NO_LEAP_YEAR 0

void drawcal(int year, int month);
int dayofweek_zeller(int year, int month);
int judgeLeap(int year);

int main(int argc, const char * argv[]) {
    // insert code here...
    int year, month;
    printf("表示したい年と月を入力してください(YYYY/MM)：");
    scanf("%d/%d", &year, &month);
    
    if (year < 1970 || year > UN_REAL_YEAR || month < 1 || month > 12) {
        printf("ERORR\n");
        return 0;
    }
    
    drawcal(year, month);
    return 0;
}

/* 指定された年・月のカレンダーを表示する */
void drawcal(int year, int month) {
    int i = dayofweek_zeller(year, month), j, lastDay = 31, february = 28;
    printf("%d/%d\n", year, month);
    puts(" Su Mo Tu We Th Fr Sa");
    /* 続きを実装せよ */
    /*1日の曜日までの空白*/
    for (j = 1; j < i+1; j++) {
        printf("   ");
        if (i % 7 == 0)
            printf("\n");
    }
    /*うるう年の判定*/
    if (judgeLeap(year) == LEAP_YEAR)
        february = 29;
    /*31日以外の月の設定*/
    switch (month) {
        case 2:
            lastDay = february;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            lastDay = 30;
            break;
    }
    i = 0;
    for (; i < lastDay; i++) {
        printf("%3d", i+1);
        if ((i+j) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

int dayofweek_zeller(int year, int month){
    int weekDays = -1, day = 1;
    if(month < 3) {
        year--;
        month += 12;
    }
    weekDays = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + day)%7;
    
    return weekDays;
}

int judgeLeap(int year){
    int leapYear;
    if (year % 4 == 0)
        leapYear = LEAP_YEAR;
    else
        leapYear = NO_LEAP_YEAR;
    if (year % 100 == 0) {
        leapYear = NO_LEAP_YEAR;
        if (year % 400 == 0)
            leapYear = LEAP_YEAR;
    }
    return leapYear;
}
