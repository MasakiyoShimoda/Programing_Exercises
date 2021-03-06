//
//  main.c
//  2-1
//
//  Created by 下田将斉 on 2016/07/04.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>

void printtime(long totalsec){
    int sec, min, hour, day;
    day = totalsec / (24 * 60 * 60);
    hour = totalsec / (60 * 60) - (day * 24);
    min = totalsec  / (60) - (day * 24 * 60) - (hour * 60);
    sec = totalsec % 60;
    
    printf("%dd %02d:%02d:%02d\n",day, hour, min, sec);
    
}

int main(int argc, const char * argv[]) {
    puts("7265秒は:");
    printtime(7265);
    
    puts("200000は:");
    printtime(200000);
    
    puts("1970年1月1日から現在までの経過時間は:");
    time_t current;
    current = time(NULL);
    printtime((long)current);
    return 0;
}
