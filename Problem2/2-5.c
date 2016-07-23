//
//  main.c
//  2-5
//
//  Created by 下田将斉 on 2016/07/23.
//  Copyright © 2016年 Masakiyo Shimoda. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define QUESTION_NUMBER 5

void count();
double microtime();
void question(int);

int main(int argc, const char * argv[]) {
  int digit = -2, start, end;

  while(digit <= 0 || digit > 5){
    printf("計算の桁数を指定してください(5桁以上不可)：");
    scanf("%d", &digit);
  }
  count();
  start = microtime();

  return 0;
}

void count(void){
  puts("3");
  sleep(1);
  puts("2");
  sleep(1);
  puts("1");
  sleep(1);
  puts("start");
}

double microtime(void){
  struct timeval tm;
  int ret;
  ret = gettomeofday(&tv, NULL);
  if(ret == 0){
    return tv.tv_sec + (double)tv.tv_usec/1000000;
  }else{
    return -1;
  }
}

void question(int digit){
  int forntNum[6] = {}, rearNum[6] = {};

  srand((unsigned int)time(NULL));
  for(i = 0; i < QUESTION_NUMBER * 2; i++ ){
  
  }

}
