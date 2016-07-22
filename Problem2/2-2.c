//
//  main.c
//  2-2
//
//  Created by 下田将斉 on 2016/07/04.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//


#include <stdio.h>
#include <time.h>
#include <limits.h>

void printtime(time_t totalsec) {
    char *wday_name[] = {"Sun","Mon", "Thu","Wed","Thu", "Fri", "Sat"};
    struct tm *timeinfo;
    timeinfo = gmtime(&totalsec);
    
    if(totalsec > 0)
        printf("%d-%02d-%02d(%s) %02d:%02d:%02d\n\n",
               timeinfo -> tm_year + 1900,
               timeinfo -> tm_mon + 1,
               timeinfo -> tm_mday,
               wday_name[timeinfo -> tm_wday],
               timeinfo -> tm_hour,
               timeinfo -> tm_min,
               timeinfo -> tm_sec
               );
    else
        puts("ERROR");
}

int main(int argc, const char * argv[]) {
    puts("7265秒は:");
    printtime(7265);
    
    puts("200000秒は:");
    printtime(200000);
    
    puts("1970年1月1日から現在までの経過時間は:");
    time_t current;
    current = time(NULL);
    printtime(current);
    
    /*符号付き32bit INT型が表示可能な最大値*/
    printf("%d秒は:\n", INT_MAX);
    printtime(INT_MAX);
    
    /*符号付き64bit　LONG型の整数が表示可能な最大値*/
    printf("%ld秒は: 表示不可\n", LONG_MAX);
    /*printtime(LONG_MAX);*/
    
    return 0;
}
