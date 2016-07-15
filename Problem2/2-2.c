//
//  main.c
//  2-2
//
//  Created by 下田将斉 on 2016/07/04.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>

void printlocaltime(time_h, csec){
    char *wday_name[] = {"Sun", "Mon" ,"Tue" ,"Wed" , "Thu", "Fri", "Sat"};
    
}

int main(int argc, const char * argv[]) {
    puts("1970年1月1日から現在までの経過時間は:");
    time_t current;
    current = time(NULL);
    printtime((long)current);
    return 0;
}
Contact GitHub API Training Shop Blog About
