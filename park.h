#ifndef _PARK_H_
#define _PARK_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define P_FAIL 0
#define P_OK 1

typedef struct LNode {
    char car_id[10];
    int month, day, hour, min, sec;
    time_t start, end;
    struct LNode *next;
}LNode;

int show();
int Menu();
int settime(LNode *table, time_t tm);
int EnCar(LNode *table);
int OutCar(LNode *table);
int display(LNode *table);

#endif