//
//  main.c
//  2-3
//
//  Created by 下田将斉 on 2016/07/15.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int dayofweek_zeller(int year, int month, int day);

int main(int argc, const char * argv[]) {
    // insert code here...
    struct tm timeinfo;
    int year = -1, month = -1, day = -1;
    char *dayname[] = {"日曜日","月曜日","火曜日","水曜日","木曜日","金曜日","土曜日"};
    
    while (year < 1582 || month > 12 || month < 1) {
        year = month = day = -1;
        printf( "Input 年月日(yyyy/mm/dd）: " );
        scanf("%d/%d/%d", &year, &month, &day);
    }
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon  = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min  = 0;
    timeinfo.tm_sec  = 0;
    time_t ct = mktime(&timeinfo);
    
    printf("%d年%d月%d日は%sです(mktime)\n",year ,month, day,dayname[timeinfo.tm_wday]);
    printf("%d年%d月%d日は%sです(zeller)\n",year ,month, day, dayname[dayofweek_zeller(year, month, day)]);
    return 0;
}

int dayofweek_zeller(int year, int month, int day){
    int weekDays = -1;
    if(month < 3) {
        year--;
        month += 12;
    }
    weekDays = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + day)%7;
    
    return weekDays;
}
