//
//  main.c
//  daysForManth
//
//  Created by 下田将斉 on 2016/05/30.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

#define FEBUARY_DAYS 28
#define SHORT_DAYS 30
#define LONG_DAYS 31

int daysForManth(int);

int main(int argc, const char * argv[]) {
    // insert code here...
    assert(daysForManth(0) == 0);
    assert(daysForManth(1) == 31);
    assert(daysForManth(2) == 28);
    assert(daysForManth(5) == 31);
    assert(daysForManth(9) == 30);
    assert(daysForManth(11) == 30);
    assert(daysForManth(12) == 31);
    assert(daysForManth('a') == 0);
    assert(daysForManth('&') == 0);
    assert(daysForManth(' ') == 0);
    printf("All Passed\n");
    
    return 0;
}

int daysForManth(month){
    int shortManth [] = {4,6,9,11};
    int i, days = LONG_DAYS;
    if(month == 0 || month > 12)
        days = 0;
    
    if (month == 2)
        days = FEBUARY_DAYS;
    
    for (i = 0; i < 4; i++) {
        if (month == shortManth[i]) {
            days = SHORT_DAYS;
            break;
        }
    }
    return days;
}
Contact GitHub API Training Shop Blog About
