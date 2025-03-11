#pragma once
#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
    int temp[6];
} Date;

void printDate(Date *);